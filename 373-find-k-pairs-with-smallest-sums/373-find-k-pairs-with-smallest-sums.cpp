class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int size1 = nums1.size(), size2 = nums2.size();
        vector<vector<int>>ans;
        priority_queue< vector<int>> minsum;
        for(int idx = 0; idx < size1 && idx < k; idx++) 
            minsum.push({-(nums1[idx] + nums2[0]),idx,0});
        while(k-- && minsum.size() > 0) {
            auto top = minsum.top();
            int idx = top[1];
            int idy = top[2];
            minsum.pop();
            ans.push_back({nums1[idx], nums2[idy]});
            if(idy + 1 < size2)
                minsum.push({-(nums1[idx] + nums2[idy + 1]), idx, idy + 1});
        }
        return ans;
    }
};