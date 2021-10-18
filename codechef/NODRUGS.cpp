#include <iostream>
using namespace std;

void check(int guy, int *arr, int n, int unit_change, int detect) {
    int max_guy = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i]>max_guy) max_guy = arr[i];
    }
    if(guy >= max_guy){
        cout<<"Yes"<<endl;
        return;
    }
    if(max_guy>guy && unit_change <=0) {
        cout<<"No"<<endl;
        return;
    }
    for(int i=1; i<detect; i++) {
        guy += unit_change;
        if(guy>max_guy){
            cout<<"Yes"<<endl;
            return;
        }
    }

    cout<<"No"<<endl;
}

int main() {
    int cases;
    cin>>cases;
    while(cases-->0) {
        int n, unit_change, detect;
        cin>>n>>unit_change>>detect;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        int guy = arr[n-1];
        check(guy, arr, n, unit_change, detect);

    }
    return 0;
}