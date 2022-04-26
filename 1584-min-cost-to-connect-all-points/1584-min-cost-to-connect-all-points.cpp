class Solution:
    def getparent(self,parent,x):
        if x == parent[x]:
            return x
        parent[x] = self.getparent(parent,parent[x])
        return parent[x]
    
    def union (self,x,y, parent,c):
        p1= self.getparent(parent,x)
        p2= self.getparent(parent,y)
        if p1!= p2:
            parent[p1]=p2
            return c
        return 0
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        N = len(points)
        parent =[ i for i in range(N)]
        arr=[]
        for i in range(N):
            for j in range(i+1,N):
                arr.append([abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),i,j])
        heapq.heapify(arr)
        cost=0
        while len(arr)>0:
            front = heapq.heappop(arr)
            cost += self.union(front[1],front[2],parent,front[0])
        return cost
        
        