class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        string n1, n2;
        n1 += s[0];
        for (int i = 1; i < s.size(); ++i) 
            i % 2 ? n2 += s[i] : n1 += s[i];
        return stoi(n1) + stoi(n2);
    }
};