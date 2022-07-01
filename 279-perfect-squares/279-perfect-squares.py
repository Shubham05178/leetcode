class Solution:
    def numSquares(self, n: int) -> int:
        dp = {}
        def solver(n):
            if n == 0 or n == 1:
                return n
            if dp.get(n,-1) != -1:
                return dp[n]
            ans = float("inf")
            for i in range(1, n//2 + 2):
                if i * i <= n:
                    ans = min(ans, 1 + solver(n - (i * i)))
                else:
                    break
            dp[n] = ans
            return dp[n]
        return solver(n)