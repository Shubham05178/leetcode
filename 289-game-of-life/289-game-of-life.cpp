/**
* Leetcode Problem - https://leetcode.com/problems/game-of-life/
* Author - Shubham Nagaria
* Date - 12th April 2022
Game of Life
**/
class Solution {
public:
    int dx[8] = {0,0,1,-1,1,-1,1,-1}, dy[8] = {1,-1,0,0,1,1,-1,-1};
    int countLive(vector<vector<int>> &Board, int i, int j, int n , int m){    
        int cnt = 0,x,y;
        for(int l = 0;l < 8;l++){
            x = i+dx[l];
            y = j+dy[l];
            cnt += x>=0 && x<n && y>=0 && y<m && Board[x][y];
        }
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size(), cnt;
        vector<vector<int>>Board = board;
        for(int i =0; i < n ; i++){
            for(int j =0; j < m ; j++){
                cnt = countLive(Board,i,j,n,m);
                if(board[i][j]){
                    if(cnt < 2 || cnt > 3)
                        board[i][j] = 0;
                }
                else{
                    if(cnt == 3)
                        board[i][j] = 1;
                }
            }
        }
    }
};