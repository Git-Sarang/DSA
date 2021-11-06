#include <iostream>
#include <vector>
using namespace std;
// Makes all the elements in 4 directions(R,L,D,U) as 'color' if they are 'key'
void floodFill(vector<vector<int>> &image, int x, int y, int key, int color, int r, int c) {
    if(x<0 || x>=r || y<0 || y>=c || image[x][y]!=key) return;
    // Special base case where the first cell is already the required color.
    if(image[x][y]==color) return;
    
    image[x][y] = color;
    floodFill(image, x+1, y, key, color, r, c);
    floodFill(image, x-1, y, key, color, r, c);
    floodFill(image, x, y+1, key, color, r, c);
    floodFill(image, x, y-1, key, color, r, c);
}
int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int color = 2;
    int key = image[1][1];
    int r = image.size();
    int c = image[0].size();
    floodFill(image, 1, 1, key, color, r, c);

    // Printing the 2D vector.
    for(auto list: image){
        for(auto num: list) cout<<num<<" ";
        cout<<endl;
    }

    return 0;
}