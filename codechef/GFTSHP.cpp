#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

signed main() {
    int cases;
    cin>>cases;
    while(cases--) {
       int n, money;
       cin>>n>>money;
       priority_queue<int, vector<int>, greater<int>> q;
       for(int i=0; i<n; i++){
           int x;
           cin>>x;
           q.push(x);
       }
        int ans = 0;

        while(money>0 && !q.empty()) {
            if(q.top() <= money) {
                money -= q.top();
                q.pop();
                ans++;
            } else if(q.top() > money) {
                double disc = (double)q.top()/(double)2;
                int price = round(disc);
                if(price<=money) {
                    ans++;
                }
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}