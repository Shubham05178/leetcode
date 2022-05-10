class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans =[]
        generator = [["(",1,0]]
        while generator:
            s , l , r = generator.pop()
            if l-r <0 or l>n or r>n:
                continue
            if l == n and r == n:
                ans.append(s)
                continue
            generator.append([s+"(",l+1,r])
            generator.append([s+")",l,r+1])
        return ans
            
        