class Solution:
    def largestWordCount(self, messages: List[str], senders: List[str]) -> str:
        mapc = dict()
        for idx in range(len(messages)):
            m = messages[idx].split(" ")
            if senders[idx] not in mapc:
                mapc[senders[idx]]=0
            mapc[senders[idx]] += len(m)
        ans=[]
        maxValue = 0
        for i in mapc.keys():
            if maxValue == mapc[i]:
                ans.append(i)
            if(maxValue < mapc[i]):
                ans = [i]
                maxValue=mapc[i]
                
        ans.sort()

        return ans[-1]
        