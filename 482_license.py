class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        ref = s.upper().replace('-', '')
        key = ''
        for i, char in enumerate(ref[::-1]):
            if i > 0 and i % k == 0:
                key += '-'
            key += char
        return key[::-1]
    