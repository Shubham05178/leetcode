class Solution {
public:
    int dx[4] = { 0,0,1,-1};
    int dy[4] = { 1,-1,0,0};
    bool dfs( int srcx, int srcy, int desx ,int desy,long int mid,vector<vector<int>>& heights, vector<vector<bool>>& vis) {
        if( srcx == desx && srcy == desy)
            return true;
        vis[srcx][srcy] = true;
        for(int id = 0; id < 4; id++){
            int x = dx[id] + srcx;
            int y = dy[id] + srcy;
            if( x >= 0 && y >= 0 && x <= desx && y <= desy && !vis[x][y] && abs(heights[srcx][srcy]-heights[x][y]) <= mid){
                if(dfs(x, y, desx, desy, mid, heights, vis))
                    return true;
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();
        long int low = 0, high = INT_MAX, mid;
        long int ans;
        while(low <= high) {
            mid = low + ((high - low) >> 1);
            vector<vector<bool>> vis (rows, vector<bool>(columns,false));
            if(dfs(0, 0, rows - 1, columns - 1, mid, heights, vis)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};