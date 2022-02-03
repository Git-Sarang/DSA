#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &m, int r, int c, int n) {
    // Finding in same col. (|)
    for(int i=0; i<n; i++) {
        if(m[i][c]==1) return false;
    }
    int row=r, col=c;
    // negative diagonal (\)
    while(row>=0 && col>=0) {
        if(m[row--][col--]==1) return false;
    }
    // positive diagonal (/)
    row=r;
    col=c;
    while(row>=0 && col<n) {
        if(m[row--][col++]==1) return false;
    }
    return true;
}

bool canForm(vector<vector<int>> &m, vector<vector<int>> &res, int r, int n) {
    vector<int> ans;
    // if r==n then we can check the whole m for an answer.
    if(r==n) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(m[i][j]==1) ans.push_back(j+1);
            }
        }
        res.push_back(ans);
        return true;
    }

    bool possible = false;
    // This loop checks for the other rows.
    // If m[i][j] is Safe then it calls for the same func. for the next row until r==n
    // Once r==n , the func. will return true, backtrack and check for other values of j in the loop.
    // If return false, it will reset the m[i][j] back to 0, bactrack and check for other values of j in loop
    for(int j=0; j<n; j++) {
        if(isSafe(m, r, j, n)) {
            m[r][j] = 1;
            possible = canForm(m, res, r+1, n) || possible;
            m[r][j] = 0;
        }
    }
    return possible;

}
int main() {
    int n = 4;
    vector<vector<int>> res;
    vector<vector<int>> m(n, vector<int>(n, 0));

    canForm(m, res, 0, n);

    for(auto x: res) {
        for(int y: x) cout<<y<<"  ";
        cout<<endl;
    }
    return 0;
}