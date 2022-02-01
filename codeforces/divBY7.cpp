#include <iostream>
// testcase not working
using namespace std;

int solve(int n) {
    if(n%7==0 && n!=0) return n;
    int rem = n%7;
    if((n%10)>=7) {
        return n-rem;
    }
    return n+(7-rem);
}

int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}