class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        rows, cols = len(matrix), len(matrix[0])
        dp = [[1 if matrix[row][col] == "1" else 0for col in range(cols)] for row in range(rows)]
        ans = 0
        for row in range(rows):
            for col in range(cols):
                if row != 0 and col != 0 and dp[row][col] == 1:
                    dp[row][col] += min(dp[row - 1][col - 1], dp[row - 1][col], dp[row][col - 1])
                ans = max(ans, dp[row][col])
        return ans * ans
        