#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// 's' is the main string and 'n' is the size of pattern-string.
vector<int> build_lps(string pat) {
    vector<int> lps(pat.size(), 0);
    int prev=0, i=1;
    int n = pat.size();
    lps[0]=0;
    while(i<n) {
        if(pat[prev]==pat[i]) {
            lps[i] = prev+1;
            prev++;
            i++;
        } else if(prev==0) {
            lps[i] = 0;
            i++;
        } else {
            prev = lps[prev-1];
        }
    }
    return lps;
}
// O(n)
int kmp(string s, string pat, vector<int> &lps) {
    // 'i' for s, 'j' for pat
    int i=0, j=0;
    // iterate the whole string 's'
    while(i<s.size()) {
        if(s[i] == pat[j]) {
            i++;
            j++;
        } else {
            // Not matched and j points at the begining of 'pat', increment 'i'
            if(j==0) i++;
            // Not matched and j is not at beginging of pat/lps, j will be left-value of the lps
            // it is pointing to.
            else j = lps[j-1];
        }
        /* 
            If j == n , that means ans is found with ending index 'i' and
            starting index 'i-n' in the string 's'
        */
        if(j==lps.size()) return i-lps.size();
    }
    // not found
    return -1;

}
int main() {
    string s = "gtsaababaaacaaaabcdqp";
    string pat = "aaacaaaa";
    vector<int> lps = build_lps(pat);
    // ANS: 8
    
    cout<<kmp(s, pat, lps)<<endl;

    return 0;
}