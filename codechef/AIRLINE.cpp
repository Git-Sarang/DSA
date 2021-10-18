#include <iostream>
using namespace std;

void check(int *arr, int luggage_cap, int hand_cap, int total) {
    if(hand_cap >= luggage_cap) {
            int max_bag = max(arr[0],max(arr[1], arr[2]));
            total -= max_bag;
            if(total <= luggage_cap) {
                cout<<"YES"<<endl;
                return;
            } else {
                cout<<"NO"<<endl;
                return;
            }
        } else {
            int closest = 0;
            for(int i=0; i<3; i++){
                if(arr[i]>closest && arr[i]<=hand_cap) closest = arr[i];
            }
            if(closest==0){
                cout<<"NO"<<endl; return;
            }
            total -= closest;
            if(luggage_cap >= total){
                cout<<"YES"<<endl;
                return;
            } else {
                cout<<"NO"<<endl;
                return;
            }

        }
}

int main() {
    int cases;
    cin>>cases;
    while (cases-->0) {
        int arr[3];
        for(int i=0; i<3; i++) cin>>arr[i];
        // int a,b,c;
        // cin>>a>>b>>c;
        int total = arr[0]+arr[1]+arr[2];
        int luggage_cap, hand_cap;
        cin>>luggage_cap>>hand_cap;

        check(arr, luggage_cap, hand_cap, total);
    }
        
    return 0;
}