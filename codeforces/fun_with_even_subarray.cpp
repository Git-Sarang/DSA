#include <iostream>
#include <stack>
using namespace std;

int solve(int *a, int n) {
    if(n==1) return 0;

    int king = a[n-1];
    stack<int> s;
    for(int i=0; i<n; i++) s.push(a[i]);
    int streak = 1, step=0;
    s.pop();
    while(!s.empty()) {
        if(s.top()==king) {
            s.pop();
            streak++;
        } else {
            step++;
            int i = streak;
            streak += i;
            while(!s.empty() && i!=0) {
                s.pop();
                i--;
            }
        }
    }

    return step;

}
int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        
        cout<<solve(a, n)<<endl;

    }
    return 0;
}