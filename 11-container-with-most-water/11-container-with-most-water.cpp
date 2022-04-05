/**
* Leetcode Problem - https://leetcode.com/problems/container-with-most-water/
* Author - Shubham Nagaria
* Date - 5th April 2022
Container With Most Water
**/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = height.size()-1, i = 0;
        int vol = INT_MIN;
        while(i<=j){
            vol= max(vol,(j-i)* min(height[i],height[j]));
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return vol;
    }
};