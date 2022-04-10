/**
* Leetcode Problem - https://leetcode.com/problems/baseball-game/
* Author - Shubham Nagaria
* Date - 10th April 2022
Baseball Game
**/
class Solution {
public:
    int stringtoint(string s){
        int x =0;
        int l = s.size();
        int i =0;
        if(s[i]=='-')
            i++;
        while(i<l){
            x=x*10+(s[i++]-'0');
        }
        if(s[0]=='-') return -x;
        return x;
    }
    int calPoints(vector<string>& ops) {
        stack<string>st;
        for(string str: ops){
            if(str== "+"){
                string s1 = st.top();
                st.pop();
                string s2=st.top();
                st.push(s1);
                st.push(to_string(stringtoint(s1)+stringtoint(s2)));
            }
          else if(str=="C"){
                st.pop();
            }
         else if(str=="D"){
                string s1 = st.top();
                st.push(to_string(stringtoint(s1)*2));
            }
            else
                st.push(str);
        }
        int sumi =0;
        while(! st.empty()){
            string s1 = st.top();
            st.pop();
            sumi+= stringtoint(s1);
        }
        return sumi;
    }
};