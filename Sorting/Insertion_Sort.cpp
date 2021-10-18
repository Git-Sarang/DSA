#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &v) {
    int i=0, key, j=0;
    for(i=1; i<v.size(); i++) {
        key = v[i];
        j = i-1;
        while(key<v[j] && j>=0) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

int main() {
    vector<int> a = {1, 3, 6, 2, 3, 8, 9};
    insertion_sort(a);
    for(auto x: a) cout<<x<<endl;
    
    return 0;
}