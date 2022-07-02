class Solution:
    def maxArea(self, h, w, horizontalCuts, verticalCuts):
        H = sorted([0] + horizontalCuts + [h])
        V = sorted([0] + verticalCuts + [w])
        return max(j-i for i,j in zip(H, H[1:])) * max(j-i for i,j in zip(V, V[1:])) % (10**9 + 7)