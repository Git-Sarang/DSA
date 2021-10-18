#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply(vector<int> v, int i) {
    int carry=0, product, res;
    vector<int> newAr;
    for(int k=0; k<v.size(); k++) {
        product = i*v[k];
        res = product + carry;
        if(res<10){
            newAr.push_back(res);
            carry = 0;
        } else {
            carry = res/10;
            res = res%10;
            newAr.push_back(res);
        }  
    }
    while(carry>0) {
        newAr.push_back(carry%10);
        carry = carry/10;
    }
     return newAr;
}

void extraLongFactorials(int n) {
    vector<int> v(1,1);
    for(int i=2; i<=n; i++) {
        v = multiply(v, i);  
    }
    reverse(v.begin(), v.end());
    for(int k=0; k<v.size(); k++){
        cout<<v[k];
    }
    cout<<endl;
}

int main() {
    extraLongFactorials(5);
    extraLongFactorials(13);
    
    return 0;
}