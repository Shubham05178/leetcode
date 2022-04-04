/**
* Leetcode Problem - https://leetcode.com/problems/is-graph-bipartite/
* Author - Shubham Nagaria
* Date - 4th April 2022
Is Graph Bipartite?
**/
class Solution {
public:
    bool dfs(int src, vector<vector<int>> &graph, vector<int> &group){
        for(auto j : graph[src]){
            if(group[j]==-1){
                group[j] = 1 - group[src];
                if(!dfs(j,graph,group)) return false;
            }
            else if(group[j]== group[src])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>group(n,-1);
        for(int i = 0; i < n; i++){
            if(group[i] == -1){
                group[i] = 1;
                if(!dfs(i,graph,group)) return false;
            }
        }
        return true;
    }
};