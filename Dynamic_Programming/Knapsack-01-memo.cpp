#include <iostream>
#include <algorithm>
using namespace std;

// All values of t are 0 as it is static
static int t[100][100];

int knapsack(int wt[], int val[], int w, int n) {
    // BASE
    if(n==0 || w==0) return 0;
    
    // Memo
    if(t[n][w] != 0) return t[n][w];
    // If weight is more, we either take or not-take, whichever gives more value.
    if(wt[n-1]<=w) {
        t[n][w] = max(val[n-1]+knapsack(wt, val, w-wt[n-1], n-1),  knapsack(wt, val, w, n-1));
        return t[n][w];
    }
    // If weight is more than capacity we don't take. 
    else if(wt[n-1] > w) {
        t[n][w] = knapsack(wt, val, w, n-1);
        return t[n][w];
    }
    return t[n][w];
}
int main() {
    // memset(t, -1, sizeof(t));
    int weights[] = {4, 5, 1};
    int val[] = {1, 2, 3};
    int n = 3;
    int w = 4;
    // ANS: 3
    cout<<knapsack(weights, val, w, n) <<endl;
    return 0;
}