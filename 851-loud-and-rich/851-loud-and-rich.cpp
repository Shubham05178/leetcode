/**
* Leetcode Problem - https://leetcode.com/problems/loud-and-rich/
* Author - Shubham Nagaria
* Date - 11th April 2022
Loud and Rich
**/
class Solution {
public:
    int dfs(int src, vector<int>&quiet,vector<int>graph[], vector<int>&res){
        int x=src;
        for(int j : graph[src]){
            if(res[j]!= -1){
                if(quiet[res[j]] < quiet[x]){
                x = res[j];
                }
            }
            else{
                 int y=dfs(j,quiet,graph,res);
                 if(quiet[y] < quiet[x])
                     x = y;
            }
        }
        return res[src]=x;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        int c = n;
        vector<int>res(n,-1);
        vector<int>graph[n];
        for(auto i : richer)
            graph[i[1]].push_back(i[0]);
        for(int i = 0; i < n; i++){
            if(res[i] == -1)
            dfs(i,quiet,graph, res);
        }
        return res;
    }
};