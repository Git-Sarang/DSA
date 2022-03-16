#include <iostream>
using namespace std;

signed main() {
    int cases;
    cin>>cases;
    while(cases--) {
       int n;
       string num;
       cin>>n>>num;
       int one=0, zero=0;
       for(char x: num) {
           if(x=='0') zero++;
           else one++;
       }
       string res = "";
       while(zero!=0) {
           res+='0';
           zero--;
       }
       while(one!=0) {
           res += '1';
           one--;
       }
       cout<<res<<endl;
    }
    return 0;
}