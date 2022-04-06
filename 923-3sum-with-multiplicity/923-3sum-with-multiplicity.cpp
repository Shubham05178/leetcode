/**
* Leetcode Problem - https://leetcode.com/problems/3sum-with-multiplicity/
* Author - Shubham Nagaria
* Date - 6th April 2022
3Sum With Multiplicity
**/
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9 + 7;
        sort(arr.begin(),arr.end());
        long int count = 0;
        int c1 =0, c2 =0,j,k,n = arr.size();
        for(int i = 0; i < n; i++){
            j = i+1;
            k = n-1;
            while(j < k){
                c1=0;
                c2=0;
                if(arr[i]+arr[j]+arr[k]==target){
                    if(arr[j] != arr[k]){
                        while(j+1 < k && arr[j]==arr[j+1]){
                            c1++;
                            j++;
                        }
                        while(k-1> j && arr[k]==arr[k-1]){
                            c2++;
                            k--;
                        }
                        k--;
                        j++;
                        c1++;
                        c2++;
                        count+= (c1*c2);
                        count%=mod;
                    }
                    else if(arr[j]==arr[k]){
                        while(j<=k && arr[j]==arr[k]){
                            c1++;
                            j++;
                        }
                        long int r = (c1*(c1-1))/2;
                        count += r;
                        count %= mod;
                    }
                }
                else if (arr[i]+arr[j]+arr[k]>target)
                    k--;
                else
                    j++;
            }
        }
        return count%mod;
    }
};