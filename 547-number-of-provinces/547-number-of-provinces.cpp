/**
* Leetcode Problem - https://leetcode.com/problems/number-of-provinces/
* Author - Shubham Nagaria
* Date - 31st March 2022
Number of Provinces
**/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        bool vis[n];
        int count = 0;
        queue<int>q;
        memset(vis,false,sizeof(vis));
        for(int i = 0 ; i < n; i++){
            if(vis[i]) continue;
            count++;
            q.push(i);
            vis[i]=true;
            while(q.size()>0){
                int x = q.front();
                q.pop();
                for(int j =0; j < n;j++){
                    if(isConnected[x][j] && !vis[j]){
                        vis[j]=true;
                        q.push(j);
                    }
                }
            }
        }
        return count;
    }
};