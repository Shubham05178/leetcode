class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
       int rows = board.size(), cols = board[0].size(), count = 0;
        for(int idx = 0; idx < rows; idx++){
            for(int idy = 0; idy <cols;idy++){
                if(board[idx][idy]=='X'){
                    if(idx-1 >= 0 && board[idx-1][idy]=='X')
                        continue;
                    if(idy-1 >= 0 && board[idx][idy-1]=='X')
                        continue;
                    count++;
                }
            }
        }
        return count;
    }
};