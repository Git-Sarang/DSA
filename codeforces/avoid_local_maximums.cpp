#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
typedef long long ll;
using namespace std;

bool check(vector<int>&v, int i, int j) {
    if(v[i+1]>v[i] && v[i+1]>v[j]) return true;
    return false;
}
int solve(vector<int> &v, int n) {
    if(n<=2) return 0;
    int ans = 0;
    int l=0, r=2;
    int maxi=-1;
    
    while(r<n) {
        if(check(v, l, r)) {
            ans++;
            v[l] = max(v[r], max(maxi,v[l+1]));
            if(r+3 >= n) {
                return ans;
            } else {
                l+=3;
                r+=3;
            }
        } else {
            l++;
            r++;
        }
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        int ans = solve(arr, n);
        cout<<ans<<endl;
        for(auto x: arr) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}