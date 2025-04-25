#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<int> st;
            vector<int>nge;
            int s=nums2.size();
            for(int n:nums1){
                auto it=find(nums2.begin(),nums2.end(),n);
                int j=(it-nums2.begin());
                for(int i=s-1; i>j; i--){
                    if(n<nums2[i]){
                        st.push(nums2[i]);
                    }
                }
                if(st.empty()){
                    nge.push_back(-1);
                }else{
                    nge.push_back(st.top());
                }
                while(!st.empty()){
                    st.pop();
                }
            }return nge;
        }
            
    };