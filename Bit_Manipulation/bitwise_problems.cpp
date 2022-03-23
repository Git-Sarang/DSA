#include <iostream>
#include <vector>
using namespace std;
int numberOfones(int n) {
    int ans = 0;
    while(n!=0) {
        n = ((n) & (n-1));
        ans++;
    }
    return ans;
}

void printSubsets(vector<char> &v) {
    int n = v.size();
    
}
int main() {
    cout<<numberOfones(5)<<endl; // 5 = 101
    cout<<numberOfones(1524)<<endl; // 1524 = 10111110100 (7 ones)

    vector<char> v = {'a', 'b', 'c'};
}