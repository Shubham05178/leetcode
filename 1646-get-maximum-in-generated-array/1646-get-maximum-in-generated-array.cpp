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
        arr[0] = 0;
        arr[1] = 1;
        int i = 2;
        int maxi = 1;
        while(i <= n){
            arr[i] = (i%2 == 1) ? arr[i/2]+arr[i/2 +1] : arr[i/2];
            maxi = max(maxi,arr[i]);
            i++;
        }
        return maxi;
    }
};