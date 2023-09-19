class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        token = s.split()
        last = 0
        for t in token:
            if t.isdigit():
                if int(t) <= last:
                    return False
                last = int(t)
        return True