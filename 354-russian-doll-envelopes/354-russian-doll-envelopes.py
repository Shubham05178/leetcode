import bisect
class Solution:
    def maxEnvelopes(self, envelopes):
        envelopes.sort(key = lambda x: (x[0], -x[1]))
        lish = []
        
        for w, h in envelopes:
            idx = bisect.bisect_left(lish, h)
            
            if idx == len(lish):
                lish.append(h)
            lish[idx] = h
            
        return len(lish)