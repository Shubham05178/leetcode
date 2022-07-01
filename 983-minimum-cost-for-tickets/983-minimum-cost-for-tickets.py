class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dayCost, weekCost, monthCost = costs
        jumpCosts = [[1, dayCost], [7, weekCost], [30, monthCost]]
        @cache
        def solver(idx):
            if idx >= len(days):
                return 0
            currDay = days[idx]
            cost = float("inf")
            for dayJump, jumpCost in jumpCosts:
                newIdx = bisect.bisect_left(days, currDay + dayJump)
                cost = min(cost, jumpCost + solver(newIdx))
            return cost
        return solver(0)
                
        
        