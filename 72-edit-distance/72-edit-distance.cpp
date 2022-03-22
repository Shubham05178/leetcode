/**
* Leetcode Problem - https://leetcode.com/problems/edit-distance/
* Author - Shubham Nagaria
* Date - 22nd March 2022
Edit Distance
**/
class Solution {
public:
    int minDistanceSolver(string &word1, string &word2, int i, int j,vector<vector<int>> &dp){
        if(i == -1 && j == -1) return 0;
        else if(i == -1 && j!= -1) return j+1;
        else if(j ==-1 && i != -1) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j])
            dp[i][j] = minDistanceSolver(word1, word2, i-1, j-1,dp);
        else
            dp[i][j] = 1 + min(minDistanceSolver(word1, word2, i-1, j,dp), min(minDistanceSolver(word1, word2, i-1, j-1,dp), minDistanceSolver(word1, word2, i, j-1,dp)));
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return  minDistanceSolver(word1, word2, n-1, m-1,dp);
    }
};