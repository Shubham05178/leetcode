/**
* Leetcode Problem - https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
* Author - Shubham Nagaria
* Date - 6th April 2022
All Ancestors of a Node in a Directed Acyclic Graph
**/
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>graph[n];
        vector<vector<int>>res(n);
        for(auto i : edges)
            graph[i[0]].push_back(i[1]);
        queue<int>q;
        bool vis[n];
        for(int i =0; i < n ; i++){
            memset(vis,false,sizeof(vis));
            q.push(i);
            vis[i]= true;
            while(q.size() > 0){
                int x = q.front();
                q.pop();
                for(int j : graph[x]){
                    if(!vis[j]){
                        vis[j]=true;
                        res[j].push_back(i);
                        q.push(j);
                    }
                }
            }
        }
        return res;
    }
};






