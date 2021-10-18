#include <iostream>
using namespace std;
class Stack{
    public:
        int top;
        int *arr;
        Stack(int size) {
            top = -1;
            arr = new int[size];
        }
        void push(int x) {
            arr[++top] = x;
        }
        int pop() {
            return arr[top--];
        }
        int peek() {
            return arr[top];
        }
        bool empty() {
            return (top<=-1);
        }
        int findMiddle(){
        }
};
class Queue{
    public:
        int front, back;
        int *arr;
        Queue(int size) {
            front = back = -1;
            arr = new int[size];
        }
        void enqueue(int x) {
            if(front==-1) front++;
            arr[++back] = x;
        }
        int dequeue() {
            if(front==-1) {
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            int res = arr[front];
            if(front==back && front!=-1) {
                front = back = -1;
            } else {
                front++;
            }
            return res;
        }
        int peek_front(){
            return arr[front];
        }
};

int main() {
    Queue q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.peek_front();
    return 0;
}