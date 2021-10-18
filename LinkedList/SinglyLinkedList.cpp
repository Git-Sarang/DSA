#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;

    Node(){
        data = 0;
        next=NULL;
    }
    Node(int n) {
        data = n;
        next = NULL;
    }
};

class SinglyLinkedList{
    public:
    Node *head;

    SinglyLinkedList() {
        head = NULL;
    }
    SinglyLinkedList(Node *ptr){
        head = ptr;
    }
    // Prints the whole List
    void printList(){
        Node *itr = head;
        while(itr != NULL){
            cout<<itr->data<<" ";
            itr = itr->next;
        }
        cout<<endl;
    }
    // Returns the length
    int size() {
        Node *tmp = head;
        int count = 0;
        while(tmp != NULL){
            count++;
            tmp = tmp->next;
        }
        return count;
    }

    // Adds a node to the end
    void append(int num) {
        Node *new_node  = new Node(num);
        if(head == NULL) {
            head = new_node;
            return;
        }
            
        Node *itr = head;
        while (itr -> next != NULL) {
          itr = itr -> next;
        }
        itr -> next = new_node;
    }
    // Adds a node to the begining
    void prepend(int num) {
        Node *new_node = new Node(num);
        new_node->next = head;
        head = new_node;
    }

    // Finds the element and returns the first index position
    int search(int key) {
        Node *itr = head;
        int i=-1;
        while(itr != NULL) {
            i++;
            if(itr->data == key) return i;
            itr = itr->next;
        }
        return -1;
    }
    // Deletes a Node with specific data   O(n)
    void deletion(int val) {
        if(head == NULL) {
            cout<<"Can't Delete. List is Empty!\n";
            return;
        }
        // If the List has only One node (Head Node)
        if(head->data == val) {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        
        Node * itr = head;
        while(itr->next->data != val) {
            itr = itr->next;
        }
        Node *toDelete = itr->next;
        itr->next = itr->next->next;
        delete toDelete;
    }

    // Reverses a List and returns the head of the reversed List
    Node *reverse() {
        Node * previous = NULL;
        Node * current = head;
        Node * nextptr;
        while(current != NULL) {
            nextptr = current->next;
            current->next = previous;
            previous = current;
            current = nextptr;
        }
        return previous;
    }
    // Recursive Reverse List function
    Node *reverse_recursive(Node * &head) {
        if (head == NULL || head->next==NULL)
            return head;
        Node* new_node = reverse_recursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_node;
    }

    // Reverses K nodes from a list and then next K nodes till the end   O(n)
    Node *reverse_k(Node *head, int k) {
        Node *previous = NULL;
        Node *current = head;
        Node *nextptr;
        int count = 0;
        while(current!=NULL && count<k) {
            nextptr = current->next;
            current->next = previous;
            previous = current;
            current = nextptr;
            count++;
        }
        if(nextptr!=NULL) {
            head->next = reverse_k(nextptr, k);
        }
        return previous;
    }
    // Makes a Cycle starting at the index position of the List
    void makeCycle_at(int index) {
        Node *tmp = head;
        Node *startNode;
        int count=0;
        while(tmp->next != NULL) {
            if(count==index) startNode = tmp;
            tmp = tmp->next;
            count++;
        }
        tmp->next = startNode;
    }
    // Returns True if the List has a cycle
    // Hare-Tortoise Algorithm
    bool hasCycle() {
        Node * fast = head;
        Node * slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) return true;
        }
        return false;
    }
    // Removes the cycle but the List has to be cyclic
    void removeCycle() {
        Node *fast = head;
        Node *slow = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) break;
        }
        fast = head;
        while(fast->next != slow->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = NULL;
    }
    // Transfers the first K elements to the end of the list
    Node* append_k(int k) {
        Node *newHead;
        Node *newTail;
        Node *tail = head;
        int count=1;
        while(tail->next != NULL) {
            if(count==k) {
                newTail = tail;
                newHead = tail->next;
            } 
            tail = tail->next;
            count++;
        }
        tail->next = head;
        newTail->next = NULL;
        // if we need a void function put head = newHead;
        return newHead;
    }

    // Intersects the second list to the First at the index position provivded
    void intersect(Node *head2, int pos) {
        Node *tmpHead = head;
        Node *tmp = head2;
        for(int i=0; i<pos; i++) {
            tmpHead = tmpHead->next;
        }
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = tmpHead;
    }

    // Merges 2 Lists in a sorted manner if both are sorted.   O(n+m)
    Node *merge(Node *head2) {
        Node *dummy = new Node(-1);
        Node *tmpDummy = dummy;
        Node *tmp1 = head;
        Node *tmp2 = head2;
        while(tmp1 != NULL && tmp2 != NULL) {
            if(tmp1->data < tmp2->data) {
                tmpDummy->next = tmp1;
                tmp1 = tmp1->next;
            } else {
                tmpDummy->next = tmp2;
                tmp2 = tmp2->next;
            }
            tmpDummy = tmpDummy->next;
        }
        while(tmp1 != NULL) {
            tmpDummy->next = tmp1;
            tmpDummy = tmpDummy->next;
            tmp1 = tmp1->next;
        }
        while(tmp2 != NULL) {
            tmpDummy->next= tmp2;
            tmpDummy = tmpDummy->next;
            tmp2 = tmp2->next;
        }
        
        return dummy->next;
    }
    // Merges 2 lists if both are sorted. Recursive.
    Node * merge_recursive(Node *l1, Node *l2) {
        Node * result;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        if(l1->data <= l2->data) {
            result = l1;
            result->next = merge_recursive(l1->next, l2);
        } else {
            result = l2;
            result->next = merge_recursive(l1, l2->next);
        }
        return result;
    }
};
int main() {
    SinglyLinkedList s1;
    s1.append(1);
    s1.append(3);
    s1.append(14);
    s1.printList();

    s1.prepend(22);
    s1.printList();

    cout<<"Position of 22 is at index "<<s1.search(22)<<endl;

    s1.deletion(22);
    s1.printList();

    SinglyLinkedList s2 = s1.reverse_recursive(s1.head);
    s2.printList();

    s1.append(2);
    s1.append(3);
    s1.append(4);
    cout<<"List: "<<endl;
    s1.printList();
    s1 = s1.reverse_k(s1.head, 2);
    cout<<"K=2 Reversed List:\n";
    s1.printList();

    cout<<s1.hasCycle()<<endl;
    s1.makeCycle_at(1);
    // s1.printList();
    cout<<s1.hasCycle()<<endl;
    s1.removeCycle();
    cout<<s1.hasCycle()<<endl;
    s1.printList();

    cout<<"Size of s1 is "<<s1.size()<<endl;

    s1 = s1.append_k(2);
    s1.printList();

    cout<<"Intersecting List 1,2,3,4 and 27,28,29 at index 2\n";
    SinglyLinkedList j1, j2;
    j1.append(1); j1.append(2); j1.append(3); j1.append(4);
    j2.append(27); j2.append(28); j2.append(29);
    j1.intersect(j2.head, 2);
    j1.printList();
    j2.printList();

    SinglyLinkedList k1, k2;
    k1.append(27); k1.append(28); k1.append(1); k1.append(4);
    k2.append(2); k2.append(3); k2.append(29);
    cout<<"k1 is: "; k1.printList(); cout<<endl;
    cout<<"k2 is: "; k2.printList(); cout<<endl;
    cout<<"Merging k1 and k2 we get:\n";
    SinglyLinkedList k3 = k1.merge(k2.head);
    k3.printList();
    
    
}