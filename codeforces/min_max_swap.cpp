#include <iostream>
#include <algorithm>
using namespace std;
int solve(int *a, int *b, int n) {
    int maxa=INT_MIN, maxb=INT_MIN;
    for(int i=0; i<n; i++) {
        if(a[i] > b[i]) swap(a[i], b[i]);
        maxa = max(maxa, a[i]);
        maxb = max(maxb, b[i]);
    }

    return maxa*maxb;
}
int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int n;
        cin>>n;
        int a[n], b[n];
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];

        cout<<solve(a, b, n)<<endl;

    }
    return 0;
}