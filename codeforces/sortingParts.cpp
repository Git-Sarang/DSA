#include <iostream>
#include <vector>
using namespace std;
bool allSame(vector<int> &v, int n) {
    int tmp = v[1];
    for(int i=2; i<=n; i++) {
        if(v[i] != tmp) return false;
    }
    return true;
}
bool isPossible(vector<int> &v, int n) {
    int mini = INT_MAX, idmin = 0, maxi=INT_MIN;
    for(int i=1; i<=n; i++) {
        maxi = max(maxi, v[i]);
        if(v[i] <= mini) {
            mini = v[i];
            idmin = i;
        }
    }
    if(maxi > n) return false;
    if(maxi >= idmin) {
        int min_second = INT_MAX;
        for(int i=maxi+1; i<=n; i++) {
            min_second = min(min_second, v[i]);
        }
        // cout<<"min_second = "<<min_second<<endl;
        if(min_second >= maxi) {
            return true;
        }

    }
    return false;
}

int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int n;
        cin>>n;
        vector<int> v(n+1);
        for(int i=1; i<=n; i++) cin>>v[i];
       
        if(allSame(v, n)) {
            cout<<"NO"<<endl;
            return 0;
        }
        
        if(isPossible(v, n)) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }

    }
    return 0;
}
