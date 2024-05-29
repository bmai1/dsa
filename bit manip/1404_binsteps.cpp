class Solution {
public:
    int numSteps(string s) {
        // 1011 (11) -> 1100 (12)

        // if all ones, add 1 to start, all ones to zero
        // otherwise swap bit in front of trailing block of 1s

        // divide? 1100 (12) -> 110 (6), removing last zero is dividing by 2

        int cnt = 0;
        while (s != "1") {
            ++cnt;
            if (s.back() == '1') {

                // int back = s.size() - 1;
                // while (back >= 0 && s[back] == '1') s[back--] = '0';
                // if (back == -1) s = "1" + s;
                // else s[back] = '1';

                while (!s.empty() && s.back() == '1') {
                    s.pop_back();
                    ++cnt;
                }
                if (s.empty()) return cnt;
                else s.back() = '1';
                
            }
            else s.pop_back();
        }
        return cnt;
    }
};