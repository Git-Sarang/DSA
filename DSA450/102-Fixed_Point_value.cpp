#include <iostream>
using namespace std;
int binarySearch(int *a, int low, int high) {
    if(high>=low) {
        int mid = (low +high)/2;
        if(mid == a[mid]) return mid;
        else if(mid > a[mid]) return binarySearch(a, mid+1, high);
        else return binarySearch(a, low, mid-1);
    }
    return -1;
}
int bs(int *a, int low, int high) {
    while(high >= low) {
        int mid = low + (high-low)/2;
        if(a[mid]==mid) return mid;
        else if(mid>a[mid]) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main() {
    int arr[10] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Fixed Point is "<< bs(arr, 0, n-1) << endl;

    return 0;
}