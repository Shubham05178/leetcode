class Solution {
	public:
		bool backspaceCompare(string s, string t) {
			stack<char>s1,s2;
      string rs,rt;
			for(char ch: s) {
				if(ch == '#' && !s1.empty())
					s1.pop();
				else if(ch != '#')
					s1.push(ch);
			}
			for(char ch: t) {
				if(ch == '#' && !s2.empty())
					s2.pop();
				else if(ch != '#')
					s2.push(ch);
			}
			while(!s1.empty()){
				rs = s1.top() + rs;
				s1.pop();
			}
			while(!s2.empty()) {
				rt = s2.top() + rt;
				s2.pop();
			}
		return rs == rt;
	}	
};