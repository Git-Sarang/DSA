#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    
    while(cases--) {
        int n;
        cin>>n;
        unordered_map<int, int> m;

        for(int i=0; i<n; i++) {
            int tmp;
            cin>>tmp;
            m[tmp]++;
        }

        int pairs = 0, alone=0;
        for(auto x: m) {
            if(x.second >= 2) {
                pairs += x.second/2;
                m[x.first] = x.second%2;
            }
        }
        for(auto x: m) {
            if(x.second==1) alone++;
        }
        pairs %= 2;
        int ans = alone;
        if(pairs==0 && (alone & 1)) {
            ans--;
            ans += 3;
        } else if(pairs==1 && !(alone & 1)) {
            ans += 2;
        }

        cout<<ans<<endl;

    }
}