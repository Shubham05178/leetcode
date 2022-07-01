class Solution:
    def numSquares(self, n: int) -> int:
        dp, squares = {}, []
        dp[0]=0
        dp[1]=1
        for i in range(1, int(math.sqrt(n)+1)):
            squares.append(i * i)
        for i in range(2, n + 1):
            dp[i] = float("inf")
            for square in squares:
                if i - square >=0:
                    dp[i] = min(dp[i], 1 + dp[i - square])
                else:
                    break
        return dp[n]