/**
* Leetcode Problem - https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
* Author - Shubham Nagaria
* Date - 31st March 2022
Minimum Number of Vertices to Reach All Nodes
**/
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>res;
        bool indegree[n];
        memset(indegree,false,sizeof(indegree));
        for(auto i : edges)
            indegree[i[1]]=true;
        for(int i = 0; i < n; i++)
            if(!indegree[i]) res.push_back(i);
        
        return res;
    }
};