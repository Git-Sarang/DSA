#include <iostream>
#include <vector>

using namespace std;

void dutchSort(vector<int> &v) {
    int low = 0, mid = 0, high = v.size()-1;

    while(mid<=high) {
        if(v[mid]==0) {
            swap(v[low], v[mid]);
            low++;
            mid++;
        }
        else if(v[mid]==1) {
            mid++;
        }
        else if(v[mid]==2) {
            swap(v[mid], v[high]);
            high--;
        }
    }
}

int main() {
    vector<int> v = {1,2,0,0,1,1,2,2,0};
    dutchSort(v);
    for(auto x: v) cout<<x<<endl;
    return 0;

}
