/**
* Leetcode Problem - https://leetcode.com/problems/reverse-string/
* Author - Shubham Nagaria
* Date - 1st April 2022
Reverse String
**/
class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int n = s.size()-1,i=0;
        while(i<n){
            temp = s[i];
            s[i] = s[n];
            s[n]= temp;
            i++;
            n--;
        }        
    }
};