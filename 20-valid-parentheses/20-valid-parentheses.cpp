/**
* Leetcode Problem - https://leetcode.com/problems/valid-parentheses/
* Author - Shubham Nagaria
* Date - 13th March 2022
Valid Parentheses
**/
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char i : s){
            if(i=='}'){
                if(st.empty()  || st.top()!='{')
                    return false;
                st.pop();
            }
            else  if(i==']'){
                if(st.empty()  || st.top()!='[')
                    return false;
                st.pop();
            }
            else if(i==')'){
                if(st.empty()  || st.top()!='(')
                    return false;
                st.pop();
            }
            else{
                st.push(i);
            }
        }
        return st.empty();
    }
};