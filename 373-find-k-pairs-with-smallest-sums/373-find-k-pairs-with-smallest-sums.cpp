class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int size1 = nums1.size(), size2 = nums2.size();
        vector<vector<int>>ans;
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int> > > minsum;
        for(int idx = 0; idx < size1; idx++) 
            minsum.push({nums1[idx] + nums2[0],idx,0});
        while(k-- && minsum.size()) {
            auto top = minsum.top();
            minsum.pop();
            ans.push_back({nums1[top[1]], nums2[top[2]]});
            if(top[2] + 1 < size2)
                minsum.push({nums1[top[1]] + nums2[top[2] + 1], top[1], top[2] + 1});
        }
        return ans;
    }
};