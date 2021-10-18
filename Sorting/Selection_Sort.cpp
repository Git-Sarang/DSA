#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> &v) {
    for(int i=0; i<v.size()-1; i++) {
        int min = i;
        for(int j=i+1; j<v.size(); j++) {
            if(v[j]<v[min]) {
                min = j;
            }
        }
        int tmp = v[i];
        v[i] = v[min];
        v[min] = tmp;

    }
}

int main() {
    vector<int> a = {1,5,2,8,2,3,5,8,9};
    for(auto x: a) cout<<x<<" "; cout<<endl;
    selection_sort(a);
    for(auto x: a) cout<<x<<" "; cout<<endl;
    return 0;
}