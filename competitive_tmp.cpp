#define ll long long
#define fop(i, n) for(int i=0; i<n; i++)
#define fom(i, n) for(int i=n; i>=0; i--)
#define vvll vector<vector<ll>> 
#define vll vector<ll>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
    fop(i, 8) cout<<i<<" ";
    vvll mat(5, vll(5, 0));

    int r = mat.size();
    int c = mat[0].size();
    fop(i, r) {
        fop(j, c) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}