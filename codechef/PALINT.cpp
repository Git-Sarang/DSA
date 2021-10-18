#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int cases;
    cin>>cases;
    while(cases-->0) {
        int n, x;
        cin>>n>>x;
        vector<int> arr(n);
        unordered_map<int, int> tally;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            tally[arr[i]]++;
        }
        int max=0, max_key;
        for(auto l: tally) {
            if(l.second > max){
                max = l.second;
                max_key = l.first;
            }
        }
        cout<<max_key;

    }    
    return 0;
}