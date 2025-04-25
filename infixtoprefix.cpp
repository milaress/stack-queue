#include<iostream>
#include<stack>
using namespace std;
//reverse functio
string reverse(string s){
    string output="";
    for(int i=s.size()-1; i>=0; i--){
        char c=s[i];
        if(c==')') {output+='(';}
        else if(c=='(') {output+=')';}
        else{
            output+=c;
        }
    }
    return output;
}
int priority(char c){
    if (c=='^') return 3;
    if (c=='*' || c=='/') return 2;
    if (c=='+' || c=='-')  return 1;
    return 0;
}
class solution{
    public:
    string infixtoprefix(string s){
        s=reverse(s);
        stack<char> st;
        string output="";
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')){
                output+=c;
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                while(st.top()!='('){
                    output+=st.top();
                    st.pop();
                }
                st.pop(); // removing the opening brace
            }
            else{
                if(c=='^'){
                    while(!st.empty()&& priority(c)==priority(st.top())){
                        output+=st.top();
                        st.pop();
                    }
                }else{
                    while(!st.empty()&& priority(c)<priority(st.top())){
                        output+=st.top();
                        st.pop();
                    }
                }
                st.push(c);
            }
        }
        while(!st.empty()){
            output+=st.top();
            st.pop();
        }
        return reverse(output);;
    }
};
