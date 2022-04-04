/**
* Leetcode Problem - https://leetcode.com/problems/possible-bipartition/
* Author - Shubham Nagaria
* Date - 4th April 2022
Possible Bipartition
**/
class Solution {
public:
    bool dfs(int src, vector<int> graph[], vector<int>& grp){
        for(auto j : graph[src]){
            if(grp[j] == -1){
                grp[j] = 1 - grp[src];
                if(!dfs(j,graph,grp)) return false;
            }
            else if( grp[j] == grp[src])
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>graph[n+1];
        for(auto i : dislikes){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<int>grp(n + 1,-1);
        for(int i = 1 ;i <= n; i++){
            if(grp[i] == -1) {
                grp[i] = 1;
                if(!dfs(i, graph, grp)) return false;
            }
        }
        return true;
    }
};