#include <iostream>
#include <map>
#define ll long long
using namespace std;
// Memoization
map<pair<int, int>, ll> memo;
ll gridtraveller(int n, int m) {
    pair<int, int> p = {n, m};
    if(n==0 || m==0) return 0;
    if(n==1 && m==1) return 1;
    if(memo.find(p) != memo.end()) return memo[p];
    memo[p] = gridtraveller(n-1, m) + gridtraveller(n, m-1);
    return memo[p];
}

// Tabulation
ll gridtraveller2(int n, int m) {
    ll t[n+1][m+1];
    // Initializiing first row and column to zero. (Base Case) Can also be done in the main loop itself.
    for(int i=0; i<n+1; i++) 
        for(int j=0; j<m+1; j++) 
            if(i==0 || j==0) t[i][j] = 0;
    // t[1][1]=1 , rest all are calculated.
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++){
            if(i==1 && j==1) t[i][j] = 1;
            else {
                t[i][j] = t[i-1][j] + t[i][j-1]; 
            }
        }
    }
    return t[n][m];
}
int main() {

    cout<<gridtraveller(3, 2)<<endl; // 3
    cout<<gridtraveller(3, 3)<<endl; // 6
    cout<<gridtraveller(0, 0)<<endl; // 0
    cout<<gridtraveller(18, 18)<<endl; // 2333606220

    cout<<gridtraveller2(3, 2)<<endl; // 3
    cout<<gridtraveller2(3, 3)<<endl; // 6
    cout<<gridtraveller2(0, 0)<<endl; // 0
    cout<<gridtraveller2(18, 18)<<endl; // 2333606220
    return 0;
}