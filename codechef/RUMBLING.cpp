#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    int cases;
    cin>>cases;
    while(cases-->0) {
        int n;
        cin>>n;
        string data;
        cin>>data;
        ll x, y;
        cin>>x>>y;

        char arr[n];
        for(int i=0 ;i<data.length(); i++) {
            arr[i] = data[i];
        }

        map<char, ll> min_w;
        min_w['N'] = min(3*x, y);
        min_w['E'] = min(2*x, 2*y);
        min_w['S'] = min(x, 3*y);
        min_w['W'] = 0;

        map<char, ll> min_e;
        min_e['S'] = min(3*x, y);
        min_e['W'] = min(2*x, 2*y);
        min_e['N'] = min(x, 3*y);
        min_e['E'] = 0;
        
        ll minn=0;
        for(int i=0; i<n; i++) {
            minn += min_w[arr[i]];
        }

        ll curr = minn;
        for(int i=0; i<n; i++) {
            curr -= min_w[arr[i]];
            curr += min_e[arr[i]];

            if(curr < minn){
                minn = curr;
            }
        }

        cout<<minn<<endl;
    }
    return 0;
}