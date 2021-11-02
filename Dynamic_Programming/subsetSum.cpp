#include <iostream>
using namespace std;
// Returns True if a subset of the array can make the given 'sum'
bool subsetSum(int arr[], int n, int sum) {
    int t[n+1][sum+1];
    // Initializing: If array size is 0 there cannot be a subset so, 'False' for i=0 i.e n=0
    //  If 'sum' is 0, there will always be a null subset so, 'True' for j=0 i.e sum=0.(Except when arr empty)
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<sum+1; j++) {
            if(i==0) t[i][j]=false;
            if(j==0) t[i][j]=true;
        }
    }    
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<sum+1; j++) {

            // If we can take
            if(arr[i-1]<=j) {
                t[i][j] = (t[i-1][j-arr[i-1]] || t[i-1][j]);
            }
            // If we cannot take the number
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,23};

    // 68: True (1+2+3+4+5+6+7+8+9+23 = 68)
    // 69: False
    cout<< subsetSum(arr, 10, 68) <<endl;
    return 0;
}