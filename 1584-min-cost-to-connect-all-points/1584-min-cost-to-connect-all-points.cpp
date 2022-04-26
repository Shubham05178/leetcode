/**
* Leetcode Problem - https://leetcode.com/problems/min-cost-to-connect-all-points/
* Author - Shubham Nagaria
* Date - 26th April 2022
Min Cost to Connect All Points
**/
class Solution {
public:
    int findParent(vector<int>& parent,int x){
        if(parent[x]==x)
            return x;
        parent[x]= findParent(parent,parent[x]);
        return parent[x];
    }
    int findUnion(int x, int y, vector<int>& parent, int c){
        int p1 = findParent(parent,x);
        int p2 = findParent(parent,y);
        if(p1!=p2){
            parent[p1]=p2;
            return c;
        }
        return 0;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int>parent(n);
        vector<vector<int>>arr;
        for(int i = 0; i < n; i++){
            parent[i] = i;
            for(int j = i+1; j < n; j++){
                arr.push_back({ abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]),i,j});
            }
        }
        sort(arr.begin(),arr.end());
        int m = arr.size();
        long int cost = 0;
        for(int i = 0; i < m; i++)
            cost+= findUnion(arr[i][1],arr[i][2],parent,arr[i][0]);
        return cost;
    }
};