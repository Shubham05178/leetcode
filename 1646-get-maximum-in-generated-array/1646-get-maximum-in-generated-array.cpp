/**
* Leetcode Problem - https://leetcode.com/problems/get-maximum-in-generated-array/
* Author - Shubham Nagaria
* Date - 23rd March 2022
Get Maximum in Generated Array
**/
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n <= 1) return n;
        int arr[n+1];
        arr[0]=0;
        arr[1]=1;
        int i = 1;
        int maxi=0;
        while(i<=n){
            maxi = max(maxi, arr[i]);
            if((i<<1)<=n)
                arr[i<<1] = arr[i];
            if((i<<1)+1<=n)
                arr[(i<<1)+1]=arr[i]+arr[i+1];
            i++;
        }
        return maxi;
    }
};