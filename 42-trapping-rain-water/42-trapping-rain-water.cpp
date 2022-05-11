class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax = 0, rightmax = 0, idx = 0, idy = height.size() - 1, ans = 0; 
        while(idx <= idy) {
            if(height[idx] <= height[idy]) {
                if(leftmax <= height[idx]) leftmax = height[idx];
                else ans += leftmax - height[idx];
                idx++;
            }
            else{
                if(rightmax <= height[idy]) rightmax = height[idy];
                else ans += rightmax - height[idy];
                idy--;
            }
        }
        return ans;
    }
};