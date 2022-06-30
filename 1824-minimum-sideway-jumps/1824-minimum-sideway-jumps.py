class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        dp=[[-1 for _ in range(3)] for _ in range(len(obstacles))]
        sys.setrecursionlimit(10**6)
        def solver(i,lane):
            if i >= len(obstacles) - 1:
                return 0
            if obstacles[i] == lane:
                return float("inf")
            if dp[i][lane - 1] != -1:
                return dp[i][lane - 1]
            if obstacles[i + 1] != lane:
                dp[i][lane - 1] = solver(i+1, lane)
            else:
                x, y = 0,0
                dp[i][lane - 1] = 1
                if lane == 1:
                    x, y = 2, 3
                elif lane == 2:
                    x, y = 1, 3
                else:
                    x, y = 1, 2
                dp[i][lane - 1] += min( solver(i, x), solver(i, y))
            return dp[i][lane-1]
        
        return solver(0,2)
                                       
                                     
        