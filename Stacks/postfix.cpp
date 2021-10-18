#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int evaluatePostfix(string s){
        stack<int> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i]!='*' && s[i]!='/' && s[i]!='+' && s[i]!='-') {
                st.push( (int)(s[i]-'0') );
            } else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(s[i]=='^'){
                    st.push(pow(b, a));
                } else if(s[i]=='*'){
                    st.push(b*a);
                } else if(s[i]=='/'){
                    st.push(b/a);
                } else if(s[i]=='+'){
                    st.push(b+a);
                } else if(s[i]=='-'){
                    st.push(b-a);
                } 
            }
        }    
        return st.top();
    
}
int main() {

    cout<<evaluatePostfix("231*+9-")<<endl;
    return 0;
}