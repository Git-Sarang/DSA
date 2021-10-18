#include <iostream>
#include <stack>
using namespace std;
void insert(stack<int> &s, int tmp) {
    if(s.empty() || s.top()<=tmp) {
        s.push(tmp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s, tmp);
    s.push(val);
}
void sort_stack(stack<int> &s) {
    if(s.size()==1) return;
    int tmp = s.top();
    s.pop();
    sort_stack(s);
    insert(s, tmp);
}

int main() {
    stack<int> myStack;
    myStack.push(5);
    myStack.push(2);
    myStack.push(6);
    myStack.push(-2);
    myStack.push(1);

    sort_stack(myStack);
    while(!myStack.empty()) {
        cout<<myStack.top()<<endl;
        myStack.pop();
    }
    return 0;
}