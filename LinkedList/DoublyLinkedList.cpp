#include <iostream>
using namespace std;
struct Node{
    Node* prev;
    int data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int x) {
        data = x;
        next=NULL;
        prev=NULL;
    }
};
class DoublyLinkedList {
    public:
    Node* head;
    Node* tail;
        DoublyLinkedList() {
            head = NULL;
            tail = NULL;
        }

        void push_end(int num) {
            Node* newNode = new Node(num);
            if(head==NULL) {
                head = newNode;
                return;
            }
            Node* tmp = head;
            while(tmp->next != NULL) {
                tmp = tmp->next;
            }
            newNode->prev = tmp;
            tmp->next = newNode;
            tail = newNode;
        }

        void printList() {
            Node* tmp = head;
            while(tmp != NULL) {
                cout<<tmp->data<<" ";
                tmp = tmp->next;
            }
            cout<<endl;
        }
        void printRev() {
            Node* tmp = tail;
            while(tmp != NULL) {
                cout<<tmp->data<<" ";
                tmp = tmp->prev;
            }
            cout<<endl;
        }
        int size() {
            Node* tmp = head;
            int count = 0;
            if(head==NULL)
                return 0;
            while(tmp!=NULL) {
                count++;
                tmp = tmp->next;
            }
            return count;
        }
        void remove(Node* n) {
            Node* toDelete = n;
            if(n==head) {
                head = n->next;
                delete toDelete;
                return;
            }
            if(n==tail) {
                tail = n->prev;
                delete toDelete;
                return;
            }
            
            Node* left = n->prev;
            Node* right = n->next;
            left->next = right;
            right->prev = left;
            delete toDelete;
        }
        void remove_idx(int num) {
            Node* tmp = head;
            for(int i=0; i<num; i++)
                tmp = tmp->next;
            remove(tmp);
        }

        void reverse() {
            Node* previous = NULL;
            Node* current = head;
            Node* next_ptr;
            while(current!=NULL) {
                next_ptr = current->next;
                current->next = previous;
                current->prev = next_ptr;
                previous = current;
                current = next_ptr;
            }
            // previous BECOMES THE FIRST NODE AND current BECOMES NULL
            head = previous;
            // TO UPDATE THE TAIL AS THE LAST NODE
            while(previous->next != NULL)
                previous = previous->next;
            tail = previous;
        }
        
        
        
};

int main() {
    DoublyLinkedList myList;
    myList.push_end(1);
    myList.push_end(2);
    myList.push_end(3);

    cout<<"List : "; myList.printList();
    cout<<"Reversd "; myList.printRev();

    cout<<"Size: "<<myList.size()<<endl;

    cout<<"Now Reversing the List"<<endl;
    myList.reverse();
    cout<<"List : "; myList.printList();
    cout<<"Reversd "; myList.printRev();

    return 0;
}