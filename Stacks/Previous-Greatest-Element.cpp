#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// Next Greatest Left
vector<int> NGL(vector<int> &arr) {
    int n = arr.size();
    vector<int> res;
    stack<int> s;
    for(int i=0; i<n; i++) {
        if(s.empty()) res.push_back(-1);
        else if(s.top()>arr[i]) res.push_back(s.top());
        else if(s.top()<=arr[i]) {
            while (!s.empty() && s.top()<=arr[i])
                s.pop();
            if(s.empty())
                res.push_back(-1);
            else
                res.push_back(s.top());
        }
        s.push(arr[i]);
    }
    return res;
}
int main() {
    vector<int> arr = {1,3,2,4};
    vector<int> res = NGL(arr);
    // ans: -1 -1 3 -1
    for(auto x: res) cout<<x<<" ";
    cout<<endl;
    return 0;
}