class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int idx = 0, size = intervals.size();
        vector<vector<int>>result;
        for(idx = 0; idx < size; ++idx) {
            if(newInterval[1] < intervals[idx][0]){
                break;
            }
            else if(!(newInterval[0] > intervals[idx][1])) {
                newInterval[0] = min(newInterval[0], intervals[idx][0]);
                newInterval[1] = max(newInterval[1], intervals[idx][1]);
            }
            else{
                result.push_back(intervals[idx]);
            }
        }
        result.push_back(newInterval);
        while(idx < size){
            result.push_back(intervals[idx++]);
        }
        return result;
    }
};