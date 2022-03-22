/**
* Leetcode Problem - https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
* Author - Shubham Nagaria
* Date - 22nd March 2022
Smallest String With A Given Numeric Value
**/
class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;
        for(int i =0; i < n ; i++)
            s+='a';
        int sum_ = n;
        for(int j = n-1; j >=0; j--){
            int diff = k -(sum_-1);
            if(diff > 0){
                if(diff > 26){
                    sum_ += 25;
                    s[j]=25+'a';
                }
                else{
                    sum_ += diff-1;
                    s[j] = (diff-1)+'a';
                }
            }
            else
                break;
        }
    return s;
    }
};