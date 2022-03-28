/**
* Leetcode Problem - https://leetcode.com/problems/reducing-dishes/
* Author - Shubham Nagaria
* Date - 28th March 2022
Reducing Dishes
**/
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int prevSum = 0, curr = 0, ans = 0;
        sort(satisfaction.begin(),satisfaction.end());
        for(int i = satisfaction.size()-1; i>=0; i--){
            curr += satisfaction[i]+prevSum;
            prevSum +=satisfaction[i];
            ans = max(ans,curr);
        }
        return ans;
    }
};