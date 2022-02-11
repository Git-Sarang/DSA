#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> res;
unordered_map<string, bool> occurred;
// Returns the no. of invalid parenthesis in a string
int getMinInvalid(string data) {
    stack<char> s;
    for(auto x: data) {
        if(x=='(' || x==')') {
            if(s.empty()) {
                s.push(x);
            } else if(x==')' && s.top()=='(') {
                s.pop();
            } else {
                s.push(x);
            }
        }
    }
    return s.size(); //stack would be left with only invalid parenthesis
}

void solve(string s, int minInv) {
    // So that we don't process the same string again
    if(occurred[s]==true) return;
    else occurred[s] = true;
    // base case
    if(minInv<0) return;

    // If there is supposed to be a valid string, it checks if the string is valid.
    // If it is, then it adds it to the res vector.
    if(minInv==0) {
        if(getMinInvalid(s)==0) {
            res.push_back(s);
        }
        return;
    }

    // Passes the string by removing the i'th char each time.
    for(int i=0; i<s.size(); i++) {
        string left = s.substr(0, i);
        string right = s.substr(i+1);
        // the string passed is without he i'th char.
        /* We do minInv-1 because we are removing one char from the string assuming it
        to be wrong char in the string */
        solve(left+right, minInv-1);
    }

}
int main() {
    string s = "()())()";
    solve(s, getMinInvalid(s));
//  ANS:  ["(())()","()()()"]
    for(auto line: res) {
        cout<<line<<endl;
    }
}