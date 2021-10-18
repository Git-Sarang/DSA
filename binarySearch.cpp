#include <iostream>
using namespace std;
// Iterative
void binSearch(int *arr, int l, int h, int x) {
    while(l<=h) {
        int mid = (l+h)/2;
        if(arr[mid] > x){
            h = mid-1;
        }else if(arr[mid] < x){
            l = mid+1;
        } else {
            cout<<mid<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
// Reccursive
int binarySearch(int *arr, int l, int h, int x) {
    if(l<=h) {
        int mid = (l+h)/2;
        if(arr[mid]>x)
            return binarySearch(arr, l, mid-1, x);
        else if(arr[mid]<x)
            return binarySearch(arr, mid+1, h, x);
        else
            return mid;
    }
    return -1;
}

int main() {
    int arr[8] = {1, 2, 4, 4, 7, 9, 14, 55};
    binSearch(arr, 0, 7, 55);

    cout<<binarySearch(arr, 0, 7, 1)<<endl;
    return 0;
}