#define ll long long
#define fop(i, n) for(int i=0; i<n; i++)
#define fom(i, n) for(int i=n; i>=0; i--)
#define vvll vector<vector<ll>> 
#define vll vector<ll>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    unordered_map<int, int> m;
    m[1] = 1;
    while(cases--) {
        int n;
        cin>>n;
        int res = 0;
        int last = 1;
        for(int i=2; i<=n; i++) {
            if(m.find(i)!=m.end()) {
                
            }
            int curr = last|i;
            if(last==curr) {
                m[i] = m[i-1]+1;
            } else {
                m[i] = m[i-1];
            }
            last = curr;
        }
        cout<<res<<endl;
    }
    return 0;
}