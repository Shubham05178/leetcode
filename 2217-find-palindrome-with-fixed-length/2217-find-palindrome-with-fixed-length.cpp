/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-286/problems/find-palindrome-with-fixed-length/
* Author - Shubham Nagaria
* Date - 27th March 2022
Find Palindrome With Fixed Length
**/
class Solution {
public:
    long long int tolong(string s){
        long long int ss=0;
        int i =0;
        int l = s.size();
        while(i<l){
            ss=ss*10+ (s[i]-'0');
            i++;
        }
        return ss;
    }
    long long int rev(long long int p, int s){
        string ss = to_string(p);
        if(ss.size()>s) return -1;
        int l = ss.size()- (s%2)-1;
        while(l>=0){
            ss+= ss[l];
            l--;
        }
        if(ss.size()>s) return -1;
        return tolong(ss);
    }
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long>res;
        int l = intLength;
        int n = (intLength-1)>>1;
        long long int elem =1;
        for(int i =0;i<n; i++){
            elem*=10;
        }
       for(int i : queries)
            res.push_back(rev(elem+(i-1),l));
        return res;
    }
};