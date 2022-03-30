/**
* Leetcode Problem - https://leetcode.com/problems/find-if-path-exists-in-graph/
* Author - Shubham Nagaria
* Date - 30th March 2022
Find if Path Exists in Graph
**/
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        vector<int>graph[n];
        for(auto i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);  
        }
        bool vis[n];
        memset(vis,false,sizeof(vis));
        queue<int>q;
        q.push(source);
        vis[source]= true;
        int x;
        while(q.size()>0){
            x = q.front();
            q.pop();
            for(auto j : graph[x]){
                if(!vis[j]){
                    if(j == destination) return true;
                    vis[j]= true;
                    q.push(j);
                }
            }
        }
        return false;
    }
};