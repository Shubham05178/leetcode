class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        bs = [ 0 for _ in range(len(prices))]
        sb = [ 0 for _ in range(len(prices))]
        mini = prices[0]
        for idx, price in enumerate(prices):
            bs[idx] = max(price - mini, bs[idx-1] if idx > 0 else bs[idx])
            mini = min(mini, price)
        maxi = prices[-1]
        for idx in range(len(prices)-1, -1, -1):
            sb[idx] = max(maxi - prices[idx], sb[idx+1] if idx<len(prices)-1 else sb[idx])
            maxi = max(maxi, prices[idx])
        maxi = 0
        for idx in range(len(bs)):
            maxi = max(maxi, bs[idx]+sb[idx])
        return maxi
        
        
        
        
#BS BS
#SBS
#bbss
#sbsb


# [3,3,5,0,0,3,1,4]

# [0, 0, 2, 2, 2,2,2,2]
# [ 4  4  4  4  3  3 0]
# 0+4 =4
# 2+4=6