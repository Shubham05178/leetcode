class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp = {}
        def mincost(idx,maxDay):
            if idx == len(days):
                return 0
            if dp.get((idx,maxDay),-1) != -1:
                return dp[(idx,maxDay)]
            if maxDay > days[idx]:
                dp[(idx,maxDay)] = mincost(idx+1, maxDay)
            else:
                dp[(idx,maxDay)] = min(costs[0]+ mincost(idx+1, days[idx]+1), costs[1] + mincost(idx+1,days[idx]+7), costs[2] + mincost(idx+1, days[idx]+30))
            return dp[(idx,maxDay)]
        return mincost(0,0)
            
                
        