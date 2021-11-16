#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> NGR(vector<int> &arr) {
    int n = arr.size();
    vector<int> res;
    stack<int> s;
    for(int i=n-1; i>=0; i--) {
        if(s.empty()) res.push_back(-1);
        else if(s.top() > arr[i]) res.push_back(s.top());
        else if(s.top() <= arr[i]){
            while(!s.empty() && s.top()<=arr[i])
                s.pop();
            if(s.empty())
                res.push_back(-1);
            else
                res.push_back(s.top());
        }

        s.push(arr[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}
int main() {
    vector<int> arr = {1,3,2,4};
    vector<int> res = NGR(arr);
    // ans: 3 4 4 -1
    for(auto x: res) cout<<x<<" ";
    cout<<endl;
    return 0;
}