/**
* Leetcode Problem - https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
* Author - Shubham Nagaria
* Date - 22nd March 2022
Smallest String With A Given Numeric Value
**/
class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int>arr(n,1);
        int sum_ = n;
        for(int j = n-1; j >=0; j--){
            int diff = k -(sum_-1);
            if(diff > 0){
                if(diff > 26){
                    sum_ += 25;
                    arr[j]=26;
                }
                else{
                    sum_ += diff-1;
                    arr[j] = diff;
                }
            }
            else
                break;
        }
        string s;
        for(int i : arr)
            s+= string(1,(i-1)+'a');
        
    return s;
    }
};