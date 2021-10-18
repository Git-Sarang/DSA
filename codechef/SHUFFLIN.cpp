#include <iostream>
using namespace std;

int main() {
    int cases;
    cin>>cases;
    while(cases-->0) {
        int n;
        cin>>n;
        int even=0, odd=0, sum=0;
        for(int i=0; i<n; i++) {
            int tmp;
            cin>>tmp;
            (tmp%2==0)? even++ : odd++;
        }

        for(int i=0; i<n; i++) {
            if(i%2==0 && even>0){
                sum++;
                even--;
            } else if(i%2!=0 && odd>0){
                sum++;
                odd--;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}