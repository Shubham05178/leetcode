class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char &ch : s) {
          if(ch == '{' || ch == '[' || ch == '(')
            st.push(ch);
          else{
            if(ch == '}' && ( st.size() == 0 || st.top() != '{'))
              return false;
            if(ch == ']' && (st.size() == 0 || st.top() != '['))
              return false;
            if(ch == ')' && (st.size() == 0 || st.top() != '('))
              return false;
            st.pop();
          }
        }
      return st.size() == 0;
    }
};