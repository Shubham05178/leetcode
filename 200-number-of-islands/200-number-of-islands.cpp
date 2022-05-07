class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    void markVisited(int x, int y, int noRows , int noCols, vector<vector<char>> &grid) {
      grid[x][y]='2';
      for(int transIdx = 0; transIdx < 4; transIdx++){
        int xnew = x + dx[transIdx];
        int ynew = y + dy[transIdx];
        if(xnew >=0 && ynew >= 0 && xnew < noRows && ynew < noCols && grid[xnew][ynew] == '1') {
          markVisited(xnew, ynew, noRows,noCols, grid);
        }
      }
    }
    int numIslands(vector<vector<char>>& grid) {
        int numIsland = 0;
        int noRows = grid.size();
        int noCols = grid[0].size();
        for(int idx = 0; idx < noRows; idx++) {
          for(int idy = 0; idy < noCols; idy++) {
              if(grid[idx][idy] == '1'){
                numIsland++;
                markVisited(idx, idy, noRows, noCols, grid);
              }          
          }
        }
      return numIsland;
    }
};