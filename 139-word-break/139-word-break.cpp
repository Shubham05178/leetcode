class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        unordered_set<string> wordset( wordDict.begin(), wordDict.end());
        vector<bool>dp(size+1, false);
        dp[0]= true;
        for(int i = 0 ; i < size; i++){
            for(int j = 0; j <= i; j++){
                if(wordset.find(s.substr(j,i+1-j)) != wordset.end()){
                    dp[i+1] = dp[i+1] || dp[j];
                    if(dp[i+1])
                        break;
                } 
            }
        }
        return dp[size];
    }
};