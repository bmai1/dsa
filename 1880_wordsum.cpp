class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int w1 = 0, w2 = 0, tsum = 0;
        for (char c : firstWord) w1 = w1 * 10 + c - 'a';
        for (char c : secondWord) w2 = w2 * 10 + c - 'a';
        for (char c : targetWord) tsum = tsum * 10 + c - 'a';
        return w1 + w2 == tsum;
    }
};