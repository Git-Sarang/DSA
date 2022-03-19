#define ll long long
#define fop(i, n) for(int i=0; i<n; i++)
#define fom(i, n) for(int i=n; i>=0; i--)
#define vvll vector<vector<ll>> 
#define vll vector<ll>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void solve(vll &a, int n) {
    stack<int> odd, even;
    fop(i, n) {
        if(a[i] & 1) odd.push(a[i]);
        else even.push(a[i]);
    }
    if(odd.size()==0 || odd.size()==1) {
        cout<<"-1"<<endl;
        return;
    }
    else if(even.size()==0) {
        if(odd.size() & 1) cout<<"-1"<<endl;
        else {
            fop(i, n) cout<<a[i]<<" ";
            cout<<endl;
        }
        return;
    }
    int k = odd.size()%2;
    int max_odd_products = odd.size()-1;

    vll ans;
    if(k==1) {
        while(odd.size()>1) {
            ans.push_back(odd.top());
            odd.pop();
        }
        while(!even.empty()) {
            ans.push_back(even.top());
            even.pop();
        }
        ans.push_back(odd.top());
        odd.pop();
    } else {
        while(!odd.empty()) {
            ans.push_back(odd.top());
            odd.pop();
        }
        while(!even.empty()) {
            ans.push_back(even.top());
            even.pop();
        }
    }
    fop(i, n) cout<<ans[i]<<" ";
    cout<<endl;

}
signed main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int n;
        cin>>n;
        vll a(n);
        fop(i, n) cin>>a[i];

        solve(a, n);
    }
    return 0;
}