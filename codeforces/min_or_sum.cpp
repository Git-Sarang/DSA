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
ll sum_arr(vector<ll> &v, int n) {
    ll sum=0;
    for(int i=1; i<=n; i++) {
        sum += v[i];
        // cout<<v[i]<<"  ";
    }
    // cout<<endl;
    return sum;
}
// arr indexing from 1
ll solve(vector<ll> &a, int n) {
    for(int i=2; i<=n; i++) {
        int x = i-1, y=i;
        ll m = a[x];
        ll n = a[y];
        ll high;
        if(n > m) {
            high = n;
        } else {
            high = m;
        }
        for(ll k=0; k<=high; k++) {
            if(high==n) {
                if((m|n) == (k|m)) {
                    a[y] = k;
                    break;
                }
            } else if(high==m) {
                if((m|n)==(k|n)) {
                    a[x] = k;
                    break;
                }
            }
        }
    }
    return sum_arr(a, n);
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll> arr(n+1);
        for(int i=1; i<=n; i++) cin>>arr[i];
        // sort(arr.begin(), arr.end());
        cout<<solve(arr, n)<<endl;
    }

    return 0;
}