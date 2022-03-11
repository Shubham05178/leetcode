/**
* Leetcode Problem - https://leetcode.com/problems/sudoku-solver/
* Author - Shubham Nagaria
* Date - 12th March 2022
Sudoku Solver
**/
class Solution {
public:
    bool isSafe(int r, int c, char i,vector<vector<char>> &board ){
        for(int l = 0 ; l < 9; l++) if(board[r][l] == i) return false;
        for(int l = 0 ; l < 9; l++) if(board[l][c] == i) return false;
        
        int sr = r - (r%3);
        int sc = c - (c%3);
        for(int l = sr;l < sr+3; l++){
            for(int p = sc; p < sc+3; p++){
                if( board[l][p] == i)
                    return false;
            }
        }
        return true;
    }
    bool solve(int index, vector<vector<char>> &board ){
        if(index == 81) return true;
        int r = index/9;
        int c = index%9;
        if(board[r][c] != '.') return solve(index+1,board);
        for(char i = '1'; i <= '9'; i++){
            if(isSafe(r,c,i,board)){
                board[r][c]= i;
               if( solve(index+1,board)) return true;
                board[r][c]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,board);
    }
};