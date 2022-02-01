#include <iostream>
using namespace std;
typedef long long ll;
bool canWin(ll hc, ll ac, ll hm, ll am, ll coins, ll a, ll h) {
    long double attempt_m = hm/ac;
    long double attempt_c = hc/am;
    if(attempt_c >= attempt_m) return true;

    for(ll i=1; i<=coins; i++) {
        ll tmp_hc = hc+h;
        ll tmp_ac = ac+a;
        long double tmp_attempt_m = hm/tmp_ac;
        long double tmp_attempt_c = tmp_hc/am;
        if( (attempt_m - tmp_attempt_c) <= (tmp_attempt_m - attempt_c)) {
            hc = tmp_hc;
        } else {
            ac = tmp_ac;
        }
        attempt_m = hm/ac;
        attempt_c = hc/am;
    }
    
    if(attempt_c >= attempt_m) return true;
    return false;

 }


int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        ll hc, ac, hm, am, coins, a, h;
        cin>>hc>>ac>>hm>>am>>coins>>a>>h;

        if(canWin(hc, ac, hm, am, coins, a, h)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }

    }
    
    return 0;
}