#include<iostream>
#include<stack>
using namespace std;

// deciding which operator has higher presedence
int priority(char c){
    if (c=='^') return 3;
    if (c=='*' || c=='/') return 2;
    if (c=='+' || c=='-')  return 1;
    return 0;
}
class Solution {
    public:
      string infixToPostfix(string& s) {
          // code here
          int i=0;
          stack<char> st;
          string output="";
          while(i<s.size()){
            //adding operands to the output
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                output+=s[i];
            }
            //finding an opening brace
            else if(s[i]=='('){
                st.push(s[i]);
            }
            //if we reach to the closing brace, then we move all the operators in the stack to the output till we reach to the opening brace then we remove it
            else if(s[i]==')'){
                while(st.top()!='('){
                    output+=st.top();
                    st.pop();
                }
                st.pop(); // removing the opening brace
            }
            //working with the operators
            else{
                while(!st.empty() && priority(s[i])<=priority(st.top())){
                    output+=st.top();
                    st.pop();//moving the operator from the stack to the output till the stack get empty
                }
                st.push(s[i]); //if the operator is less presedence than than the top of the stack, we push it anyways
            }
            i++;
          }
          while(!st.empty()){
            output+=st.top();
            st.pop();
          }
          return output;
      }
  };
  