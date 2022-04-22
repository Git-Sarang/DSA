#define ll long long
#define fop(i, n) for(int i=0; i<n; i++)
#define fom(i, n) for(int i=n; i>=0; i--)
#define vvll vector<vector<ll>> 
#define vll vector<ll>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve(int x, int y) {
    if((x&1) && (y&1)){
        cout<<-1<<endl;
        return;
    } else if(x%2==0 && y%2==0) {
        for(int i=0; i<x/2; i++) cout<<'a';
        for(int i=0; i<y; i++) cout<<'b';
        for(int i=0; i<x/2; i++) cout<<'a';
        cout<<endl;
        for(int i=0; i<y/2; i++) cout<<'b';
        for(int i=0; i<x; i++) cout<<'a';
        for(int i=0; i<y/2; i++) cout<<'b';
        cout<<endl;
        return;
    } else if(x>1 && y>1){
        if(x&1) {
            for(int i=0; i<y/2; i++) cout<<'b';
            for(int i=0; i<x; i++) cout<<'a';
            for(int i=0; i<y/2; i++) cout<<'b';
        } else {
            for(int i=0; i<x/2; i++) cout<<'a';
            for(int i=0; i<y; i++) cout<<'b';
            for(int i=0; i<x/2; i++) cout<<'a';
        }
        cout<<endl;
        int outer;
        if(x>y) {
            outer = x-y+1;
            for(int i=0; i<outer/2; i++) cout<<'a';
            for(int i=0; i<y; i++) cout<<"ba";
            for(int i=0; i<(outer/2)-1; i++) cout<<'a';
        } else {
            outer = y-x+1;
            for(int i=0; i<outer/2; i++) cout<<'b';
            for(int i=0; i<y-1; i++) cout<<"ab";
            for(int i=0; i<(outer/2)-1; i++) cout<<'b';
        }
        cout<<endl;
        return;

    } else {
        cout<<-1<<endl; return;
    }


}

signed main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int x, y;
        cin>>x>>y;
        solve(x, y);
    }
    return 0;
}