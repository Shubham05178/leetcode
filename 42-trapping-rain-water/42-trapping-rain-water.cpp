class Solution {
public:
    int trap(vector<int>& height) {
      int n = height.size(), waterTrap = 0, mini;
	    vector<int>leftMax(n), rightMax(n);
	    for(int i = 1; i < n; i++)
		    leftMax[i] = max(leftMax[i-1], height[i-1]);
	    for(int i = n - 2; i >= 0; i--)
		    rightMax[i] =  max(rightMax[i + 1], height[i + 1]);
	    for(int i = 1; i < n - 1; i++){
		      mini = min(rightMax[i], leftMax[i]) - height[i];
		      if(mini > 0)   waterTrap += mini;
	      }
	    return waterTrap;
    }
};