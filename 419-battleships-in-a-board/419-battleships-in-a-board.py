class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        n = len(board)
        m = len(board[0])
        count = 0
        for i in range(n):
            for j in range(m):
                if board[i][j]=='X':
                    if ( i > 0 and board[i-1][j]=='X' )or  (j  > 0 and board[i][j-1] =='X'):
                        continue
                    count += 1
        return count
        