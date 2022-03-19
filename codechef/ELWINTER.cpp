#define ll long long
#define fop(i, n) for(int i=0; i<n; i++)
#define fom(i, n) for(int i=n; i>=0; i--)
#define vvll vector<vector<ll>> 
#define vll vector<ll>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

signed main() {
    int v, e, queries;
    cin>>v>>e>>queries;
    unordered_map<int, vector<int>> adj;
    vector<int> frozen(1e9+3);
    queue<int> qu;
    for(int i=0; i<e; i++) {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // vll query = {1, 2, 3};
    fop(i, queries) {
        int type, val;
        cin>>type>>val;
        if(type==1) {
            qu.push(val);
            frozen[val] = 1;
        } else if(type==2) {
            for(int j=0; j<val; j++) {
                int n = qu.size();
                for(int l=0; l<n; l++) {
                    int curr = qu.front();
                    qu.pop();
                    for(auto num: adj[curr]) {
                        if(frozen[num]==0) {
                            frozen[num]=1;
                            qu.push(num);
                        }
                    }
                }
            }
        } else if(type==3) {
            if(frozen[val]==1) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}