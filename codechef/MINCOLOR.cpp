#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

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
        int par1 = (x1+y1)%2;
        int par2 = (x2+y2)%2;
        if(par1!=par2) {
            int first = (par1==0)?1:2;
            int second = (par1==1)?1:2;
            for(int i=0; i<r; i++) {
                for(int j=0; j<c; j++) {
                    if((i+j)%2 == 0) mat[i][j] = first;
                    else mat[i][j] = second;
                }
            }
        } else {
            int first = (par1==0)?1:4;
            int second = (par1==0)?4:1;
            for(int i=0; i<r; i++) {
                for(int j=0; j<c; j++) {
                    if((i==x1 && j==y1) || (i==x2 && j==y2)) {
                        continue;
                    } else {
                        if((i+j)%2 == 0) mat[i][j] = first;
                        else mat[i][j] = second;
                    }
                }
            }
        }
        print_mat(mat, r, c);
    }
    return 0;
}