/**
* Leetcode Problem - https://leetcode.com/problems/remove-stones-to-minimize-the-total/
* Author - Shubham Nagaria
* Date - 22nd April 2022
Remove Stones to Minimize the Total
**/
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int>pq;
        long int sumi =0;
        for(int i: piles){
            sumi += i;
            pq.push(i);
        }
        while(k--){
           int x= pq.top();
            pq.pop();
            if(x==0)
                break;
            sumi -= x;
            x-=floor(x/2);
            sumi +=x;
            pq.push(x);
        }
        return sumi;
    }
};