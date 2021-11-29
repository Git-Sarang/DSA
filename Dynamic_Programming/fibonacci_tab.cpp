#include <iostream>
#define ll long long
using namespace std;
// Set every element to zero
// Iterate and add the last 2 elements to the current one.
ll fib(int n) {
    ll t[n+1];
    memset(t, 0, sizeof(t)); //sets all values of 't' to 0
    t[1] = 1;
    for(int i=2; i<n+1; i++) {
        t[i] = t[i-1] + t[i-2];
    }
    return t[n];
}
int main() {

    cout<<fib(6)<<endl; // 8
    cout<<fib(7)<<endl; // 13
    cout<<fib(8)<<endl; // 21
    cout<<fib(50)<<endl; // 12586269025
    return 0;
}