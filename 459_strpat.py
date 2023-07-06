class Solution(object):
    def repeatedSubstringPattern(self, s):
        return s in (2 * s)[1:-1]

        # Consider a string S="helloworld". Now, given another string T="lloworldhe".
        # Can we figure out if T is a rotated version of S? Yes, we can! We check if S is a substring of T+T.
