class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        ans = []
        w1 = s1.split()
        w2 = s2.split()
        for w in w1:
            if w1.count(w) == 1 and w not in w2:
                ans.append(w)
        
        for w in w2:
            if w2.count(w) == 1 and w not in w1:
                ans.append(w)
        
        return ans