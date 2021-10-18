#include <iostream>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    while(cases-->0) {
        int n, district, state;
        string data;
        cin>>n>>district>>state;
        cin>>data;
        int tot = 0;
        for(int i=0; i<data.length(); i++){
            if(data[i]=='0') tot += district;
            else tot += state;
        }
        cout<<tot<<endl;
    }
    return 0;
}