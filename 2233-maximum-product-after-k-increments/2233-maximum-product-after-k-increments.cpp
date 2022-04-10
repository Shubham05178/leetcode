/**
* Leetcode Problem - https://leetcode.com/problems/maximum-product-after-k-increments/
* Author - Shubham Nagaria
* Date - 10th April 2022
https://leetcode.com/problems/maximum-product-after-k-increments/
**/
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod =1e9+7;
        priority_queue<int,vector<int>, greater<int> >pq;
        for(int i : nums)
            pq.push(i);
        while(k){
            int x = pq.top();
            pq.pop();
            if(pq.size()>0 && pq.top()-x !=0 && pq.top()-x <= k){
                int diff =(pq.top()-x);
                x+= diff;
                pq.push(x);
                k-=diff;
            }
            else{
              pq.push(x+1);
               k--;
            }
        }
        long long int mul =1;
        while(pq.size()>0){
            mul*= pq.top();
            pq.pop();
            mul%= mod;
        }
        return mul%mod;
    }
};