#include <iostream>
using namespace std;
int knapsack(int wt[], int val[], int w, int n) {
    int t[n+1][w+1];
    // Initializiing first row and column to zero. (Base Case) Can also be done in the main loop itself.
    for(int i=0; i<n+1; i++) 
        for(int j=0; j<w+1; j++) 
            if(i==0 || j==0) t[i][j] = 0;
    // Main loop 'i'->'n' and 'j'->'w'
    // Completely related to Recursive counterpart 
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<w+1; j++) {
            if(wt[i-1]<=j) {
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else if(wt[i-1]>j){
                t[i][j] = t[i-1][j];
            }
        }
    }
    // Last value of the table has the answer.
    return t[n][w];      
}
int main() {
    int weights[] = {4, 5, 1};
    int val[] = {1, 2, 3};
    int n = 3;
    int w = 4; 
    // ANS: 3
    cout<<knapsack(weights, val, w, n) <<endl;
    return 0;
}