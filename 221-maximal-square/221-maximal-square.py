class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n, m = len(matrix), len(matrix[0])
        dp = [[0 for _ in range(m)] for _ in range(n)]
        ans = 0
        for idx in range(n):
            for idy in range(m):
                if matrix[idx][idy]=="1":
                    dp[idx][idy] = 1
                if idx != 0 and idy != 0 and dp[idx][idy] == 1:
                    dp[idx][idy] += min(dp[idx-1][idy-1], dp[idx-1][idy], dp[idx][idy-1])
                ans = max(ans, dp[idx][idy])
                        
        return ans*ans
        