#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &tree, int mid, int target) {
    int sum = 0;
    for(int i=0; i<tree.size(); i++) {
        if(tree[i] > mid) {
            sum += tree[i]-mid;
        }
        if(sum >= target) return true;
    }
    return false;
}

int main() {
    int n, target, max_h=0;
    cin>>n>>target;
    vector<int> tree(n);
    for(int i=0; i<n; i++) {
        cin>>tree[i];
        max_h = max(max_h, tree[i]);
    }

    int l=0, r=max_h, ans=0;
    while(l < r) {
        int mid = l + (r-l)/2;
        if(check(tree, mid, target)) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cout<<ans<<endl;



}