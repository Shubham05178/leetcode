class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), res = 0, x, y, z, newx, newy, newz;;
        vector<vector<int>>vis(n, vector<int>(m, INT_MAX));
        queue<vector<int>>que;
        que.push({0, 0, grid[0][0]});
        while(que.size()){
            int size = que.size();
            while(size--){
                auto front = que.front();
                que.pop();
                x = front[0];
                y = front[1];
                z = front[2];
                if(x == n - 1 && y == m - 1)
                    return res;
               for(int idx = 0; idx < 4; idx++){
                    newx = x + dx[idx];
                    newy = y + dy[idx];
                    if(newx >= 0 && newy >= 0 && newx < n && newy < m){
                         newz = z + grid[newx][newy];
                         if(newz < vis[newx][newy] && newz <= k){
                            vis[newx][newy] = newz;
                            que.push({newx, newy, newz});
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};