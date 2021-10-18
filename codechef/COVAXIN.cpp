// THIS IS NOT AN OPTIMISED SOLUTION
#include <iostream>
typedef long long ll;

using namespace std;
void update_values(ll &a, ll &b, ll &c, ll &d, ll p, ll q, ll r, ll s, ll t, ll m, int ans){
    a = (a + ans*t) % m + p;
    b = (b + ans*t) % m + q;
    c = (c + ans*t) % m + r;
    d = (d + ans*t) % m+ s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int queries;
    cin>>queries;
    ll money, a, b, c, d;
    cin>>money>>a>>b>>c>>d;
    ll p,q,r,s,t,m;
    cin>>p>>q>>r>>s>>t>>m;

    int i=0;
    int ans=0;
    while(i<queries) {
        if(i>0) {
            update_values(a, b, c, d, p, q, r, s, t, m, ans);
        }
        ll curr_cost = 0;
        int covax=0, covis=0;
        while(true) {
            ll cost_covax = a + (covax)*b;
            ll cost_covis = c + (covis)*d;
            if(cost_covax < cost_covis) {
                curr_cost += cost_covax;
                if(curr_cost > money){
                    curr_cost -= cost_covax;
                    break;
                }
                covax++;
            } else {
                if(curr_cost+cost_covis <= money) {
                    curr_cost += cost_covis;
                    covis++;
                } else{
                    break;
                }
            }
        }
        ans = covax + covis;
        cout<<ans<<endl;


        i++;

    }

    return 0;
}