class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentList;
        vector <vector<bool>>palli(s.size(), vector<bool>(s.size(), false));
        int i = 0, j = 0;
        while(j < s.size()){
            int i_ = 0, j_=j;
            while(i_< s.size() && j_ < s.size()){
                if(i_==j_){
                    palli[i_][j_]= true;
                }
                else if(j_- i_ ==1 ){
                    if(s[j_]==s[i_])
                        palli[i_][j_]=true;
                }
                else{
                    if(s[j_]==s[i_])
                        palli[i_][j_]=true;
                    palli[i_][j_] = palli[i_][j_] && palli[i_ + 1][j_ - 1 ];
                }
                i_++;
                j_++;
            }
            j++;
        }
        dfs(result, s, 0, currentList, palli);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList,  vector <vector<bool>> &palli) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (palli[start][end]){
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, palli);
                currentList.pop_back();
            }
        }
    }
   
};

