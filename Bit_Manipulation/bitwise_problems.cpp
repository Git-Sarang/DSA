#include <iostream>
#include <vector>
using namespace std;
// Number of setbits
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
    for(int i=0; i< (1<<n); i++) {
        for(int j=0; j<n; j++) {
            if( i & (1<<j)) {
                cout<<v[j]<<" ";
            }
        }
        cout<<endl;
    }
}
int main() {
    cout<<numberOfones(5)<<endl; // 5 = 101
    cout<<numberOfones(1524)<<endl; // 1524 = 10111110100 (7 ones)

    vector<char> v = {'a', 'b', 'c'};
    printSubsets(v);
}