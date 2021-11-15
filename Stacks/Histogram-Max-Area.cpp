#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int largestRectangleArea(vector<int>& arr) {
    vector<int> nsl, nsr;
    int n = arr.size();
    stack<pair<int, int>> s, s2;
    // Finds the Next Lowest Number to the Left of the current
    for(int i=0; i<n; i++) {
        if(s.size()==0) nsl.push_back(-1);
        else if(s.size()>0 && s.top().first < arr[i])
            nsl.push_back(s.top().second);
        else if(s.size()>0 && s.top().first >= arr[i]) {
            while(s.size()>0 && s.top().first>=arr[i])
                s.pop();
            if(s.size()==0)
                nsl.push_back(-1);
            else
                nsl.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }
    // Finds the Next Lowest Number to the right of the current one.
    for(int i=n-1; i>=0; i--) {
        if(s2.size()==0) nsr.push_back(n);
        else if(s2.size()>0 && s2.top().first < arr[i])
            nsr.push_back(s2.top().second);
        else if(s2.size()>0 && s2.top().first >= arr[i]) {
            while(s2.size()>0 && s2.top().first>=arr[i])
                s2.pop();
            if(s2.size()==0)
                nsr.push_back(n);
            else
                nsr.push_back(s2.top().second);
        }
        s2.push({arr[i], i});
    }
    // Reversing is required as the vector has been indexed from the back.
    // Can be avoided if we directly put in the indexing.
    reverse(nsr.begin(), nsr.end());
    
    // Area = height * (NSR-NSL-1)
    int maxi = 0;
    for(int i=0; i<n; i++) {
        maxi = max(maxi, arr[i]*(nsr[i] - nsl[i]-1));
    }
    return maxi;
}

signed main() {
    vector<int> histograms = {6, 2, 5, 4, 5, 1, 6};
    // Ans: 12
    cout<<largestRectangleArea(histograms)<<endl;
    return 0;
}