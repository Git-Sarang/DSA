#include <iostream>
using namespace std;

// Circular queue is memory efficient as it can store the elements
// in the space created after dequeue operation.
struct CircularQueue{
    int SIZE;
    int front, rear;
    int *arr;
    CircularQueue(int s){
        SIZE = s;
        front = rear = -1;
        arr = new int[SIZE];
    }
    void enqueue(int n) {
        if((front==0 && rear==SIZE-1) || rear == front-1) {
            cout<<"Queue is full!"<<endl;
            return;
        }
        else if(front==-1) {
            front = rear =0;
            arr[rear] = n;
        } else if(rear==SIZE-1 && front!=0) {
            rear = 0;
            arr[rear] = n;
        } else {
            rear++;
            arr[rear] = n;
        }
    }

    int dequeue(){
        int data;
        if(front==-1) {
            cout<<"Queue is empty!"<<endl;
            return -1;
        } else if(front==rear) {
            data = arr[front];
            front = rear = -1;
        } else if(front==SIZE-1) {
            data = arr[front];
            front = 0;
        } else {
            data = arr[front];
            front++;
        }
        return data;
    }

    void printQueue() {
        if(front==-1) {
            cout<<"Queue is empty!"<<endl;
            return;
        }

        if(rear >= front) {
            for(int i=front; i<=rear; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        else {
            for(int i=front; i<SIZE; i++)
                cout<<arr[i]<<" ";
            for(int i=0; i<=rear; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.printQueue();

    q.dequeue();
    q.printQueue();

    q.enqueue(99);
    q.printQueue();

    return 0;
}