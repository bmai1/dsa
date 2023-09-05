class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split()
        ans = 0
        for word in words:
            ans += 1
            for c in word:
                if c in brokenLetters:
                    ans -= 1
                    break
        return ans