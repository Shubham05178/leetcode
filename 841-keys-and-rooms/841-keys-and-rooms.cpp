/**
* Leetcode Problem - https://leetcode.com/problems/keys-and-rooms/
* Author - Shubham Nagaria
* Date - 31st March 2022
Keys and Rooms
**/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        bool vis[n];
        memset(vis,false,sizeof(vis));
        queue<int>q;
        vis[0]=true;
        q.push(0);
        while(q.size()>0){
            int roomkey = q.front();
            q.pop();
            for(int j : rooms[roomkey]){
                if(!vis[j]){
                    vis[j]=true;
                    q.push(j);
                }
            }
        }
        for(int i = 0; i < n; i++)
            if(!vis[i]) return false;
        return true;
    }
};