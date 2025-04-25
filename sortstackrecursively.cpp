#include<iostream>
#include<stack>
using namespace std;
class Solution{
    void insertsorted(stack<int> st, int element){
        if(st.empty()||st.top()<element){
            st.push(element);
            return;
        }// the element is smaller than the top
        int top=st.top();
        st.pop();
        //after popping, now we check this great element with the element before the smaller top
        insertsorted(st, element);
        st.push(top);
    }
    void sortstack(stack<int> st){
        if(!st.empty()){
            int top=st.top();
            st.pop();
            sortstack(st);//untill all the elements are popped outs
            insertsorted(st, top);
        }
    }
};