class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<pair<string,pair<int,int>>>generator;
        vector<string>ans;
        generator.push({"(",{1,0}});
        while(generator.size()) {
            auto toppair = generator.top();
            generator.pop();
            int l = toppair.second.first;
            int r = toppair.second.second;
            string topstr = toppair.first;
            if(l - r < 0 || l > n || r > n )
                continue;
            if(l == n && r == n){
                ans.push_back(topstr);
                continue;
            }
            generator.push({topstr+")",{l,r+1}});
            generator.push({topstr+"(", {l+1,r}});
        }
        return ans;
    }
};