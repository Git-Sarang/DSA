#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solve(vector<pair<int, int>> &rooks, int row, int col, int n) {
    if(n==0) return row*col;
    priority_queue<int> q_rows, q_cols;
    for(int i=1; i<=n; i++) {
        q_rows.push(rooks[i].first);
        q_cols.push(rooks[i].second);
    } 

    int max_height = row - q_rows.top();
    int max_width = col - q_cols.top();
    int last_row = q_rows.top();
    q_rows.pop();
    int last_col = q_cols.top();
    q_cols.pop();
    for(int i=0; i<n-1; i++) {
        int curr_h = last_row - q_rows.top()-1;
        int curr_w = last_col - q_cols.top()-1;
        last_row = q_rows.top();
        q_rows.pop();
        last_col = q_cols.top();
        q_cols.pop();
        max_height = max(max_height, curr_h);
        max_width = max(max_width, curr_w);
    }
    max_height = max(max_height, last_row-1);
    max_width =  max(max_width, last_col-1);
    return max_width * max_height;
}

int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int row, col, n;
        cin>>row>>col>>n;
        vector<pair<int, int>> rooks(n+1);
        for(int i=1; i<=n; i++) {
            int a, b;
            cin>>a>>b;
            rooks[i] = {a, b};
        }
        
        cout<<solve(rooks, row, col, n)<<endl;

    }
    return 0;
}