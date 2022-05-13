class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int j = nums.size()-1;
        int i = 1, Size = nums.size();
        vector<int>ans(nums.begin(),nums.end());
        sort(ans.begin(), ans.end());
        while(i < Size){
            nums[i]= ans[j];
            i+=2;
            j--;
        }
        i = 0;
        while(i<Size){
            nums[i]= ans[j];
            j--;
            i+=2;
        }
    }
};