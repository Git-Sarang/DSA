#include <iostream>
#include <map>
using namespace std;
map<pair<int,int>, int> memo;
int eggDropping(int eggs, int floors) {
    if(memo.find({eggs, floors}) != memo.end()) return memo[{eggs, floors}];
    if(floors==0 || floors==1) return floors;
    if(eggs==1) return floors;

    int mn = INT_MAX;
    for(int k=1; k<=floors; k++) {
        int res = max(eggDropping(eggs-1, k-1), eggDropping(eggs, floors-k));
        mn = min(mn, res);
    }
    // +1 for the current trial
    memo[{eggs, floors}] = mn + 1;
    return memo[{eggs, floors}];
}

int main() {
    cout<<eggDropping(2, 10)<<endl; // 4
    cout<<eggDropping(4, 55)<<endl;
    return 0;
}