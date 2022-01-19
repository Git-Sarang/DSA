#include <vector>
#include <iostream>
using namespace std;
int longestIncreasingSum(vector<int> &arr) {
    int n = arr.size();
    int t[n];
    for(int i=0; i<n; i++) t[i] = arr[i];

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i]) {
                t[i] = max(t[i], t[j]+arr[i]);
            }
        }
    }
    int ans = INT_MIN;
    for(int i=0; i<n; i++) ans = max(ans, t[i]);
    return ans;
}
void longestIncreasingSumSubsequence(vector<int> &arr) {
    int n = arr.size();
    int t[n];
    int s[n];
    for(int i=0; i<n; i++){
        t[i] = arr[i];
        s[i] = i;
    } 

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i] && t[j]+arr[i]>t[i]) {
                t[i] = max(t[i], t[j]+arr[i]);
                // storing the index from where the max is coming from
                s[i] = j;
            }
        }
    }
    int myMax=arr[0];
    int myMax_index = 0;
    for(int i=1; i<n; i++) {
        if(t[i] > myMax) {
            myMax = t[i];
            myMax_index = i;
        }
    }
    while(myMax_index != 0) {
        cout<<arr[myMax_index]<<" ";
        myMax_index = s[myMax_index];
    }
    cout<<arr[0]<<endl;
}
int main() {
    vector<int> arr = {1, 101, 2, 3, 100};
    cout<<longestIncreasingSum(arr)<<endl;
    cout<<"Subsequence is: ";
    longestIncreasingSumSubsequence(arr);
    return 0;
}