// NOT WORKING!! 
#include <iostream>
using namespace std;
// This gives the largest Sub-Array Sum     O(n)
int kadane_max(int n, int *a) {
    int max_c = a[0], max_g = a[0];
    for(int i=1; i<n-1; i++) {
        if(a[i] > max_c + a[i]){
            max_c = a[i];
        } else {
            max_c += a[i];
        }

        if(max_c > max_g) max_g = max_c;
    }
    return max_g;
}
// THis gives the lowest Sub-Array Sum      O(n)
int kadane_min(int n, int *a) {
    int min_c=a[0], min_g=a[0];
    for(int i=0; i<n-1; i++) {
        if(a[i] < min_c + a[i]) min_c = a[i];
        else min_c = min_c + a[i];

        if(min_c < min_g) min_g = min_c;
    }
    return min_g;
}

int main() {
    int n=10;
    int arr[10] = {1,2,3,4,5,6,7,-8,-1,10};

    cout<<kadane_max(n, arr)<<endl;
    cout<<kadane_min(n, arr)<<endl;
    return 0;
}