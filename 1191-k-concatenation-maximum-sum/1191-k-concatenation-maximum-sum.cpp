/**
* Leetcode Problem - https://leetcode.com/problems/k-concatenation-maximum-sum/
* Author - Shubham Nagaria
* Date - 23rd April 2022
K-Concatenation Maximum Sum
**/
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int mod = 1e9+7, m = min(k, 2);
        long long int maxSum = 0, currSum = 0,totalsum = 0;
        while(m--){
            totalsum = 0;
            for(int i: arr){
                currSum += i;
                totalsum += i;
                maxSum = max(maxSum,currSum);
                if(currSum < 0)
                    currSum = 0;
            }
        }
        return max(maxSum, k>2 ? maxSum+totalsum * (k-2):0)%mod;
    }
};