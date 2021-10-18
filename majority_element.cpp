#include <iostream>
using namespace std;
// BOYER MOORE VOTING ALGORITHM
// if the element is more than size/2 times in the array then it is a majority element
int majorityElement(int *a, int size) {
    int maj = a[0];
    int curr = 1;
    for(int i=1; i<size; i++) {
        if(a[i] != maj) curr--;
        else curr++;
        
        if(curr==0){
            curr=1;
            maj = a[i];
        }
    }
    
    int count_maj=0;
    for(int i=0; i<size; i++) {
        if(a[i]==maj) count_maj++;
    }
    if(count_maj > size/2) return maj;
    return -1;
}
int main() {
    int arr[7] = {3,1,2,3,3,4,3};
    cout<<majorityElement(arr, 7)<<endl;
}
