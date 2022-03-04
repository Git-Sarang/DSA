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
bool check(ll num, ll x, ll n) {

    if(x>=0 && x<=num*(n-1)) return true;
    return false;
}
signed main() {
    int cases;
    cin>>cases;
    while(cases--) {
        ll n, s;
        cin>>n>>s;
        ll num = n+1;
        ll ans = 0;

        cout<<(s/(n*n))<<endl;
    }
    
    return 0;
}