#include <iostream>
typedef long long ll;
using namespace std;
bool check(int *arr, int n, ll mid, int prata_req) {
    int count=0;
    ll time=0;
    for(int i=0; i<n; i++) {
        time = arr[i];
        int j =2;
        while(time<=mid) {
            time += arr[i]*j;
            count++;
            j++;
        }
        if(count>=prata_req) return true;
    }
    return false;
}
int main() {
    int cases;
    cin>>cases;
    while(cases-->0) {
        int n, prata_req;
        cin>>prata_req>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];

        int l=0;
        // ll h = (ll) 10 *prata_req*(prata_req+1)/2;
        ll h = 1e8;
        ll ans=-1;
        while(l<=h) {
            ll mid = l + (h-l)/2;
            if(check(arr, n, mid, prata_req)) {
                ans = mid;
                h = mid-1;
            } else {
                l = mid+1;
            }
        }

        cout<<ans<<endl;

    }
    return 0;
}