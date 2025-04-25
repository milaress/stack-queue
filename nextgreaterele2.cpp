#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n=nums.size();
            vector<int>nge(n,0);
            stack<int> st;
            for(int i=(2*n)-1;i>=0;i--){ //citcular array has 2n length, we start in the reverse way
                while(!st.empty()&&st.top()<=nums[i%n]){ //if the descening order is interrupted, we start popping out the top
                    st.pop();
                }
                if(i<n){ //once we entre the real array elements we start adding the nge 
                    nge[i]= st.empty()? -1: st.top();
                }
                st.push(nums[i%n]);
            }
            return nge;
        }
    };