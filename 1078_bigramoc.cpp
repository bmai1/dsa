class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        words = text.split()
        ans = []
        if len(words) <= 2:
            return ans
        for i in range(len(words) - 2):
            if words[i] == first and words[i + 1] == second:
                ans.append(words[i + 2])
        return ans