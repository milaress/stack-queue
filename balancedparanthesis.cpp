#include<iostream>
#include<stack>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            for(int i=0; i<s.size(); ++i){
                char c=s[i];
                if(c=='(' || c=='{'|| c=='['){
                    st.push(c);
                }
                else{
                    if(st.empty()) return false; //if the string starts with closing brakets
                    if(c==')' && st.top()!='(') return false;
                    if(c=='}' && st.top()!='{') return false;
                    if(c==']' && st.top()!='[') return false;
                    st.pop();
                }
            }
            return st.empty(); //no unmatched brackets
        }
    };