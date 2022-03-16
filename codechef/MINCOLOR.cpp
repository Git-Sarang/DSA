#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

int find_num(set<int> &s) {
    for(int i=1; i<1e9; i++) {
        if(s.find(i)==s.end()) return i;
    }
    return 1e9;
}
void fill(vector<vector<int>>&mat, int i, int j, int r, int c) {
    set<int> s;
    if(i+1<r) {
        s.insert(mat[i+1][j]);
    }
    if(i-1>=0) {
        s.insert(mat[i-1][j]);
    }
    if(j+1<c) {
        s.insert(mat[i][j+1]);
    }
    if(j-1>=0) {
        s.insert(mat[i][j-1]);
    }
    int num = find_num(s);
    mat[i][j] = num;
    s.clear();
}

void print_mat(vector<vector<int>>&mat, int r, int c) {
    for(int i=0; i<r; i++) {
           for(int j=0; j<c; j++) {
               cout<<mat[i][j]<<" ";
           }
           cout<<endl;
       }
}
signed main() {
    int cases;
    cin>>cases;
    while(cases--) {
       int r,c;
       cin>>r>>c;
       int x1, y1, x2, y2;
       cin>>x1>>y1>>x2>>y2;
       x1--; y1--; x2--; y2--;
       vector<vector<int>> mat(r, vector<int>(c, 0));
       mat[x1][y1] = 1;
       mat[x2][y2] = 2;
       vector<vector<int>> visited(r, vector<int>(c, 0)); 
       queue<pair<int, int>> q;
       q.push({x1,y1});
       q.push({x2, y2});
       visited[x1][y1] = 1;
       visited[x2][y2] = 1;
       while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(mat[i][j]==0) fill(mat, i, j, r, c);
            if(i+1<r  && visited[i+1][j]==0) {
                q.push({i+1, j});
                visited[i+1][j] = 1;
            }
            if(i-1>=0  && visited[i-1][j]==0) {
                q.push({i-1, j});
                visited[i-1][j] = 1;
            }
            if(j+1<c && visited[i][j+1]==0) {
                q.push({i, j+1});
                visited[i][j+1] = 1;
            }
            if(j-1>=0  && visited[i][j-1]==0) {
                q.push({i, j-1});
                visited[i][j-1] = 1;
            }
       }
    //    for(int i=0; i<r; i++) {
    //        for(int j=0; j<c; j++) {
    //            if(mat[i][j]==0) {
    //                fill(mat, i, j, r, c);
    //            }
    //        }
    //    }

       print_mat(mat, r, c);
    }
    return 0;
}