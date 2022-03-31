/**
* Leetcode Problem - https://leetcode.com/problems/redundant-connection/
* Author - Shubham Nagaria
* Date - 31st March 2022
Redundant Connection
**/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>graph[n+1];
        vector<int>res;
        for(auto i : edges){
            queue<int>q;
            bool vis[n+1];
            memset(vis,false,sizeof(vis));
            q.push(i[0]);
            vis[i[0]]=true;
            while(q.size()>0){
                int x = q.front();
                q.pop();
                for(auto j : graph[x]){
                    if(!vis[j]){
                        if(j == i[1]) 
                            res = i;
                        vis[j]= true;
                        q.push(j);
                    }
                }
            }
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            
            }
        
        return res;
    }
};