class Solution {
public:
    int dx[4]={ 0,0,-1,1};
    int dy[4]= {1,-1,0,0};
    void dfs(int idx, int idy, vector<vector<int>>&grid, vector<vector<bool>> &vis, bool &makeitNoncount, int rw, int rc){
        if(idx == 0 || idy == 0 || idx == rw - 1 || idy == rc-1)
            makeitNoncount = false;
        vis[idx][idy]=true;
        for(int dir =0; dir < 4; ++dir){
            int x = idx+ dx[dir];
            int y = idy + dy[dir];
            if(x>=0 && y>=0 && x<rw && y< rc && grid[x][y]==0 && !vis[x][y]){
               dfs(x,y,grid,vis, makeitNoncount, rw, rc);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int rw = grid.size(), rc = grid[0].size();
        vector<vector<bool>>vis(rw, vector<bool>(rc,false));
        bool makeitNoncount;
        int count = 0;
        for(int idx = 0; idx<rw; idx++){
            for(int idy =0; idy<rc; ++idy){
                makeitNoncount = true;
                if(!vis[idx][idy] && grid[idx][idy] == 0){
                    dfs(idx,idy,grid,vis,makeitNoncount, rw, rc);
                    if(makeitNoncount)
                        count++;
                }
            }
        }
        return count;
    }
};