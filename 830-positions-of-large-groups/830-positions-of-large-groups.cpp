class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int size = s.size(), low = 0;
        vector<vector<int>>ans;
        for(int idx = 0; idx < size; idx++){
            if(s[idx] != s[idx + 1]){
                if(idx - low >= 2)
                   ans.push_back({low, idx});
                 low = idx + 1;
            }
        }
        return ans;
    }
};