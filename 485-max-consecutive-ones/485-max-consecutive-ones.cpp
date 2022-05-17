class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, chain = 0;
        for(int &i : nums ){
            if(i == 0)
                chain = 0;
            else
                chain++;
            maxCount = max(maxCount, chain);
        }
        return maxCount;
    }
};