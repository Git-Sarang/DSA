#include <iostream>
using namespace std;
// 1D memoization
int t[100];
int fib(int n) {
    // Base case
    if(n<=1) return n; 

    if(t[n] != 0) return t[n];
    
    t[n] = fib(n-1) + fib(n-2);
    return t[n];
}
int main() {
    cout<<"Fib of 3: "<<fib(3)<<endl;
    cout<<"Fib of 18: "<<fib(18)<<endl;
    cout<<"Fib of 20: "<<fib(20)<<endl;
    return 0;
}