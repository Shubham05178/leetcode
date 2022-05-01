class Solution {
	public:
		bool backspaceCompare(string s, string t) {
      string rs,rt;
			for(char ch: s) {
        if(ch != '#')
          rs.push_back(ch);
        else if(rs.size() > 0)
          rs.pop_back();
      }
      for(char ch: t) {
        if(ch != '#')
          rt.push_back(ch);
        else if(rt.size() > 0)
          rt.pop_back();
      }
		return rs == rt;
	}	
};