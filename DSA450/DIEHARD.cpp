#include <iostream>
typedef long long ll;
using namespace std;
int solve(int h, int a) {
    int count=0;
    char curr_form;
    
    curr_form = 'a';
    h += 3;
    a += 2;
    
    while(h>0 && a>0) {
        count++;
        if(h>20 and a<=10 and curr_form=='a') {
            h-=20;
            a+=5;
            curr_form = 'f';
        } else if(curr_form=='a'){
            h-=5;
            a-=10;
            curr_form = 'w';
        } else if(curr_form=='w' || curr_form=='f') {
            h+=3;
            a+=2;
            curr_form = 'a';
        }
    }
    return count;
}
int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int h, a;
        cin>>h>>a;
        cout<<solve(h, a)<<endl;
    }
    return 0;
}