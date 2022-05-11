class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int size = intervals.size();
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int idx = 1; idx < size; idx++){
            if(ans.back()[1] >= intervals[idx][0]){
                ans.back()[1] = max(ans.back()[1],intervals[idx][1]);
            }
            else{
                ans.push_back(intervals[idx]);
            }
        }
        return ans;
    }
};