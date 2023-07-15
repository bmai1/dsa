class Solution:
    def romanToInt(self, s: str) -> int:
        num = 0
        for index, digit in enumerate(s):
            match digit:
                case "I":
                    num += 1
                case "V":
                    num += 5
                case "X":
                    num += 10
                case "L":
                    num += 50
                case "C":
                    num += 100
                case "D":
                    num += 500
                case "M":
                    num += 1000
            try:
                next = s[index + 1]
                match digit:
                    case "I":
                        if next == "V" or next =="X":
                            num -= 2
                    case "X":
                        if next == "L" or next == "C":
                            num -= 20 
                    case "C":
                        if next == "D" or next == "M":
                            num -= 200             
            except IndexError:
                pass           
        return num