#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        string data;
        cin>>data;
        unordered_map<int, int> m;
        m[0]=0;
        m[1]=0;
        for(char x: data) {
            if(x=='0') m[0]++;
            else m[1]++;
        }
        if(m[0]==m[1]) cout<<0<<endl;
        else cout<<min(m[0], m[1])<<endl;
    }
    return 0;
}