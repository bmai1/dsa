class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> tmp;
        for (int i = 0; i < chars.size(); ++i) {
            int count = 0;
            char curr = chars[i];
            // count consecutive repeating characters
            while (i < chars.size() && chars[i] == curr) {
                ++count, ++i;
            }
            tmp.push_back(curr);
            // append digits as characters 
            if (count >= 10) {
                for (char c : to_string(count)) {
                    tmp.push_back(c);
                }
            }
            else if (count != 1) {
                tmp.push_back(count + '0');
            }
            // go back one index; while loop breaks on new character
            --i;
        }
        chars = tmp;
        return tmp.size();

        // Wrong answer for [a,a,b,b,a,a]
        // set<int> s(chars.begin(), chars.end());
        // for (auto it = s.begin(); it != s.end(); ++it) {
        //     int c = count(chars.begin(), chars.end(), *it);
        //     if (c == 1) {
        //         tmp.push_back(*it);
        //     }
        //     else {
        //         tmp.push_back(*it);
        //         stack<int> s;
        //         while (c > 0) {
        //             s.push(c % 10);
        //             c /= 10;
        //         }
        //         while (!s.empty()) {
        //             tmp.push_back(s.top() + '0');
        //             s.pop();
        //         }
        //     }
        // }
        // chars = tmp;
        // return tmp.size(); 
    }
};
