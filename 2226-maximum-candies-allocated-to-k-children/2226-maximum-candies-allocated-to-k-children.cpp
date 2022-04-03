/**
* Leetcode Problem - https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
* Author - Shubham Nagaria
* Date - 3rd April 2022
Maximum Candies Allocated to K Children
**/
class Solution {
public:
    bool check(long long int mid,long long int k,vector<int> &candies){
        if (mid ==0)return true;
        long long int c =0;
        int n = candies.size();
        for(int i = 0; i < n; i++){
            c+= candies[i]/mid;
            if(c>=k) return true;
        }
        return c >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
       long long int sum = 0;
        for(int i :candies)
            sum+=i;
        if(sum<k) return 0;
        long long int h = sum/k, l = 0,ans, mid;
        while(l<=h){
            mid = l + ((h-l)>>1);
            bool f = check(mid,k,candies);
            if(f){
                ans = mid;
                l = mid + 1;
            }
            else{
                h = mid-1;
            }
        }
        return ans;
    }
};