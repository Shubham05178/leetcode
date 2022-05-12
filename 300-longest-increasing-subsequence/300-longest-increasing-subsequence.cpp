class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        for( int i : nums){
        int idx =  lower_bound(lis.begin(),lis.end(),i) - lis.begin();
            if(idx==lis.size())
                lis.push_back(i);
            lis[idx]=i;
        }
        return lis.size();
    }
};