#include <iostream>
#include <algorithm>
using namespace std;
// This gives the largest Sub-Array Sum     O(n)
// T: O(n) S:O(n)
int kadane_max(int n, int *a) {
    int t[n+1];
    t[0] = 0;
    int ans = a[0];
    for(int i=1; i<=n; i++) {
        t[i] = max(a[i-1], t[i-1]+a[i-1]);
        ans = max(ans, t[i]);
    }
    return ans;
}

int kadane_max_op(int n, int *a) {
    int tmp = 0, ans = a[0];
    for(int i=0; i<n; i++) {
        tmp = max(a[i], a[i]+tmp);
        ans = max(ans, tmp);
    }
    return ans;
}
int main() {
    int n=10;
    int arr[10] = {1,2,3,4,5,6,7,-8,-1,10};

    cout<<kadane_max(n, arr)<<endl;
    cout<<kadane_max_op(n, arr)<<endl;
    return 0;
}