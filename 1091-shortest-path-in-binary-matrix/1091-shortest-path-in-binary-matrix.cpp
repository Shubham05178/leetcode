class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>>vis(rows, vector<bool>(cols,false));
        int distance = 0, size;
        queue<pair<int,int>>travelled;
        if(grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1) return -1;
        travelled.push({0,0});
        vis[0][0] = true;
        int dx[8] = {0,0,1,-1,1,-1,-1,1};
        int dy[8] = {1,-1,0,0,1,-1,1,-1};
        while(travelled.size() > 0){
            distance++;
            size = travelled.size();
            while(size--) {
                auto front = travelled.front();
                travelled.pop();
            if(front.first == rows - 1 && front.second == cols - 1)
                return distance;
                for(int idx = 0; idx < 8; ++idx) {
                    int xnew = front.first + dx[idx];
                    int ynew = front.second + dy[idx];
                    if(xnew >= 0 && ynew >= 0 && xnew < rows && ynew < cols && !vis[xnew][ynew] && grid[xnew][ynew] == 0){
                        vis[xnew][ynew] = true;
                         travelled.push({xnew, ynew});  
                    } 
                }
            }
        }
        return -1;
    }
};