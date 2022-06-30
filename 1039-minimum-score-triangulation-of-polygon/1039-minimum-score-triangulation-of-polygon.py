class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        @cache
        def solver(i,j):
            ans = float("inf")
            for k in range(i+1, j):
                ans = min(ans, values[i]*values[k]*values[j] + solver(i,k) + solver(k,j))
            if ans == float("inf"):
                return 0
            return ans
        return solver(0,len(values)-1)
        