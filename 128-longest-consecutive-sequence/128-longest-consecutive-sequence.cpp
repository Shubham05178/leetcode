class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        int size = nums.size(), maxlen = 0, chainlen, searchingelement;
        for(int idx = 0; idx < size; idx++){
            chainlen =1;
            if(s.find(nums[idx]-1) == s.end()){
               searchingelement = nums[idx] + 1;
                while(s.find(searchingelement) != s.end()) {
                    chainlen++;
                    searchingelement++;
                }
                maxlen = max(maxlen, chainlen);
            }
        }
        return maxlen;
    }
};