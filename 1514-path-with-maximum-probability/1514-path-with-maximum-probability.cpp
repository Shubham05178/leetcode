/**
* Leetcode Problem - https://leetcode.com/problems/path-with-maximum-probability/
* Author - Shubham Nagaria
* Date - 9th April 2022
Path with Maximum Probability
**/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>graph[n];
        int m = edges.size();
        for(int i = 0;i < m; i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>prob(n,0);
        prob[start]=1;
        queue<int>q;
        q.push(start);
        while(q.size()>0){
            int x = q.front();
            q.pop();
            for(auto i : graph[x]){
                if(prob[x]*i.second>prob[i.first]){
                    prob[i.first]= prob[x]*i.second;
                    q.push(i.first);
                }
            }
        }
        return prob[end];
    }
};