class Solution:
    def reformat(self, s: str) -> str:
        l = ""
        d = ""
        res = ""

        for c in s:
            if c.isdigit():
                d += c
            else:
                l += c

        if abs(len(l) - len(d)) > 1:
            return ""

        # interlace strings
        if len(l) < len(d):
            l, d = d, l

        for i in range(len(l) + len(d)):
            if i % 2 == 0:
                res += l[i // 2]
            else:
                res += d[i // 2]

        return res
        
        # for i in range(min(len(l), len(d))):
        #     res += l[i] + d[i]

        # if len(l) > len(d):
        #     res += l[-1]

        # return res