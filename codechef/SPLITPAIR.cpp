#define ll long long
#define fop(i, n) for(int i=0; i<n; i++)
#define fom(i, n) for(int i=n; i>=0; i--)
#define vvll vector<vector<ll>> 
#define vll vector<ll>
#include <iostream>
#include <vector>
using namespace std;
bool solve(int n) {
    int odd=0, even=0;
    while(n>0) {
        int k = n%10;
        cout<<k<<" ";
        // if(k%2==0 || k==0) even++;
        // else odd++;

        // if(even>=2 || odd>=2) return true;
        n /= 10;
    }
    return false;
}
signed main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int n;
        cin>>n;
        int tmp = n;
        int non_zero=0, num=0;

        if(solve(n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}