/**
* Lwetocode Problem - https://leetcode.com/problems/pacific-atlantic-water-flow/
* Author - Shubham Nagaria
* Date - 23rd April 2022
Pacific Atlantic Water Flow
**/
class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    void dfs(int i , int j ,vector<vector<int>>&vis,vector<vector<int>>& heights,int n, int m){
        vis[i][j]=1;
        for(int l =0;l < 4;l++){
            int x = i + dx[l];
            int y = j + dy[l];
            if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && heights[i][j] <= heights[x][y])
                dfs(x,y,vis,heights,n,m);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>>vis1(n,vector<int>(m)),vis2(n,vector<int>(m)),res;
        for(int i =0 ; i <n ; i++){
            if(!vis1[i][0])
                dfs(i,0,vis1,heights,n,m);
        }
        for(int j =0 ; j <m;j++){
            if(!vis1[0][j])
                dfs(0,j,vis1,heights,n,m);
        }
        for(int i =0 ; i <n ; i++){
            if(!vis2[i][m-1])
                dfs(i,m-1,vis2,heights,n,m);
        }
        for(int j =0 ; j <m;j++){
            if(!vis2[n-1][j])
                dfs(n-1,j,vis2,heights,n,m);
        }
        for(int i =0;i <n;i++){
            for(int j =0; j <m;j++){
                if(vis1[i][j]==vis2[i][j] && vis1[i][j]==1)
                           res.push_back({i,j});
            }
        }
        return res;
    }
};