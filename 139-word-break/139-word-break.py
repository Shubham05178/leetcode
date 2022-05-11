class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        arr = [False for _ in range(len(s)+1)]
        arr[0]=True
        for i in range(len(s)):
            for j in range(i+1):
                if s[j:i+1] in wordDict:
                    arr[i+1] = arr[i+1] or arr[j]
        return arr[-1]