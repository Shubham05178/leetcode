/**
* Leetcode Problem - https://leetcode.com/problems/validate-stack-sequences/
* Author - Shubham Nagaria
* Date - 16th March 2022
Validate Stack Sequences
**/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int n = pushed.size();
        int j = 0;
        for(int i =0; i < n;i++){
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[j] && j<n ){
                j++;
                st.pop();
            }
        }
        return st.empty();
    }
};