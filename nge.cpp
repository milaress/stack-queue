#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution{
    vector<int>NGE(vector<int>arr){
        stack<int>st;
        vector<int>nge(arr.size(),0);//this is where the nge will be stored
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty()&&st.top()<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i]=-1;
            }else{
                nge[i]=st.top(); 
            }
            st.push(arr[i]);
        }
        return nge;
    }
};