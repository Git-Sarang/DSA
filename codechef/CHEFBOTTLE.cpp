#include <iostream>
using namespace std;

signed main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int n, x, k;
        cin>>n>>x>>k;
        int ans = k/x;
        if(ans>n) cout<<n<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}