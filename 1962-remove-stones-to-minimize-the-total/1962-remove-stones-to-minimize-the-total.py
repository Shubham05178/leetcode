# Date - 24th April 2022
import heapq
class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        sumi =sum(piles)
        piles=[-i for i in piles]
        heapq.heapify(piles)
        while k>0:
            k-=1
            maxi = -heapq.heappop(piles)
            sumi-=maxi
            maxi -= maxi//2
            sumi +=maxi
            heapq.heappush(piles,-maxi)
        return sumi