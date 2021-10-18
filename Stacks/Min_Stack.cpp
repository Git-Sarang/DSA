#include <iostream>
using namespace std;
class Stack {
    public:
        int top;
        int min_top;
        int *arr;
        int *minArr;

        Stack(int size) {
            arr = new int[size];
            minArr = new int[size];
            top = min_top = -1;
        }
        void push(int val) {
            arr[++top] = val;
            if(min_top >= 0) {
                if(val < minArr[min_top]) {
                    minArr[++min_top] = val;
                } else {
                    minArr[min_top+1] = minArr[min_top];
                    min_top++;
                }
            } else {
                minArr[++min_top] = val;
            }
        }
        void pop() {
            top--;
            min_top--;
        }
        int getMin() {
            return minArr[min_top];
        }
        int getTop(){
            return arr[top];
        }
};

int main(){
    Stack s(6);
    s.push(1);
    s.push(3);
    s.push(7);
    s.push(9);
    s.push(10);

    cout<<s.getTop()<<endl;
    cout<<s.getMin()<<endl;
    return 0;
}
