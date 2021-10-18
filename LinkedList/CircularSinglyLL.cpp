#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node *next;
    Node(int n) {
        data = n;
    }
};

void insert_head(Node * &head, int val) {
    Node *newNode = new Node(val);
    if(head==NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node *tmp = head;
    while(tmp->next != head){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->next = head;
    head = newNode;

}

void insert_tail(Node * &head, int val) {
    Node *newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    Node *tmp = head;
    while(tmp->next != head) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->next = head;

}

void print_once(Node *head) {
    Node *tmp = head;
    while(tmp->next != head) {
        cout<<tmp->data<<"->";
        tmp = tmp->next;
    }
    cout<<tmp->data<<"->";
    cout<<"REPEAT\n";
}

// Removes the element from the given index(We use &head as reference var cus we need to update it's actual value)
void pop(Node* &head, int index) {
    Node *tmp = head;

    if(index==0) {
        Node *toDelete = head;
        while(tmp->next != head) tmp = tmp->next;
        tmp->next = head->next;
        head = head->next;
        delete toDelete;
        return;
    }

    int count = 0;
    // We need the pointer on the previous Node of the Node that is to be deleted
    while(count != index-1) {
        tmp = tmp->next;
        count++;
    }
    Node *toDelete = tmp->next;
    tmp->next = tmp->next->next;
    delete toDelete;
}

int main() {
    Node *head = NULL;
    insert_tail(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    print_once(head);
    
    insert_head(head, 64);
    print_once(head);

    pop(head, 0);
    print_once(head);
    return 0;
}