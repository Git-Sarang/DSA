// Stack implemented with dubly linkedlist with mid operation
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int x){
        data = x;
        next=NULL;
        prev=NULL;
    }
};
class Stack{
    public:
    Node *top;
    Node *mid;
    int size=0;
    void push(int x) {
        if(size==0) {
            top = new Node(x);
            mid = top;
            size++;
            return;
        }
        size++;
        Node *tmp = new Node(x);
        top->next = tmp;
        tmp->prev = top;
        top = tmp;
        if(size%2==1) {
            mid = mid->next;
        }
    }
    int pop() {
        Node *toDelete = top;
        int res = top->data;
        top = top->prev;
        delete toDelete;
        size--;
        return res;
    }
    int pop_mid() {
        Node *toDelete = mid;
        mid->prev->next = mid->next;
        mid->next->prev = mid->prev;
        int res = mid->data;
        size--;
        if(size%2==0) {
            mid = mid->next;
        }else {
            mid = mid->prev;
        }
        delete toDelete;
        return res;
    }
    int peek() {
        return top->data;
    }
    int peek_mid() {
        return mid->data; 
    }
    void printStack() {
        Node *tmp = top;
        while(tmp!=NULL) {
            cout<<tmp->data<<" ";
            tmp = tmp->prev;
        }
        cout<<endl;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(69);
    s.pop();
    s.printStack();
    cout<<s.pop_mid()<<endl;
    s.printStack();
    cout<<s.pop_mid()<<endl;
    s.printStack();
    cout<<s.peek_mid();
    return 0;
}
