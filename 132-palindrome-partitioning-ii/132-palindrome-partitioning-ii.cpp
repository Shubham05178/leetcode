/**
* Leetcode Problem - https://leetcode.com/problems/palindrome-partitioning-ii/
* Author - Shubham Nagaria
* Date - 4th April 2022
Palindrome Partitioning II
**/
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n==1) return 0;
        vector<int>dp( n, INT_MAX);
        dp[0]=0;
        vector<vector<int>>palindrome(n, vector<int>(n,9));
        int j =0, i_, j_;
        while(j<n){
           i_=0, j_=j;
            while(i_ < n && j_ < n){
                if(i_ == j_)
                    palindrome[i_][j_] = 1;
                else if(s[i_]== s[j_]){
                    palindrome[i_][j_] = 1;
                    if( j_ - i_ >1)
                         palindrome[i_][j_] = palindrome[i_ + 1][j_ - 1];
                }
                else 
                     palindrome[i_][j_] = 0;
                i_++;
                j_++;
            }
            j++;
        }
        dp[1]=1;
        if(s[0]==s[1])
            dp[1]=0;
        for(int i =2 ; i < n ;i++){
            if(palindrome[0][i] == 1) dp[i]=0;
            else{
                for(int j =1; j <=i ; j++){
                    if(palindrome[j][i] == 1){
                        dp[i] = min(dp[i], 1+ dp[j-1]);
                    }
                }   
            }
        }
        return dp[n-1];
    }
};