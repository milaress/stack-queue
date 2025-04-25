#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class solution{
    public:
    string prefixtopostfix(string s){
        reverse(s.begin(),s.end());
        stack<string> st;
        for(char ch:s){
            string c(1, ch);//convert char to string

            if(isalnum(ch)){
                st.push(c);
            }else if(c == "+" || c == "-" || c == "*" || c == "/" || c == "^"){
                string op1=st.top(); st.pop();
                string op2=st.top(); st.pop();
                string output=op1+op2+c;
                st.push(output);
            }
        }
        return st.top();
    }
};