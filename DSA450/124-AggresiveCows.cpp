#include <iostream>
#include <algorithm>
using namespace std;

bool checkCows(int *arr, int size, int mid_num, int cows) {
    int count=1, last = arr[0];
    for(int i=1; i<size; i++) {
        int curr_dist = arr[i] - last;
        if(curr_dist >= mid_num) {
            count++;
            last = arr[i];
        }
        if(count==cows) return true;
    }
    return false;
}

int main() {
    int cases;
    cin>>cases;
    while (cases-->0) {
        int n, cows;
        cin>>n>>cows;
        int shops[n];
        for(int i=0;i<n;i++)cin>>shops[i];
        sort(shops, shops+n);
        int l=shops[0], h=shops[n-1];
        int ans=-1;
        while(l<=h) {
            int mid = (l+h)/2;
            if(checkCows(shops, n, mid, cows)) {
                l = mid+1;
                ans = mid;
            } else {
                h = mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}