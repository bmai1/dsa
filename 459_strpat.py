class Solution(object):
    def repeatedSubstringPattern(self, s):
        return s in (2 * s)[1:-1]
