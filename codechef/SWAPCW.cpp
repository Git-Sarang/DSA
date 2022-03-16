#include <iostream>
using namespace std;
void check(int n, string s) {
    char prev = s[0];
    for(int i=1; i<n; i++) {
        if(prev > s[i]) {
            cout<<"NO"<<endl;
            return;
        }
        prev = s[i];
    }
    cout<<"YES"<<endl;
}
signed main() {
    int cases;
    cin>>cases;
    while(cases--) {
       int n;
       string s;
       
       cin>>n>>s;
       int l=0, h=n-1;
       while(l<h) {
           if(s[l] > s[h]) {
               swap(s[l], s[h]);
           }
           l++;
           h--;
       }
       check(n, s);
    }
    return 0;
}