/**
* Leetcode Problem - https://leetcode.com/problems/count-sorted-vowel-strings/
* Author - Shubham Nagaria
* Date - 24th March 2022
Count Sorted Vowel Strings
**/
class Solution {
public:
    int Ncr(int n , int r){
        int m= min(r,n-r);
        long long mul1 =1 ,mul2=1;
        while(m>0){
            mul1 *= m;
            mul2 *= n;
            n--;
            m--;
        }
        return mul2/mul1;
    }
    int countVowelStrings(int n) {
        return Ncr(5+n-1,n);
    }
};