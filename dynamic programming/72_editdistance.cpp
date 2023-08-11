class Solution {
private:
    unordered_map<string, int> dp;
    string tail(string& word) {
        return word.substr(1, word.size() - 1);
    }
public:
    int minDistance(string w1, string w2) {
        string key = w1 + "#" + w2; 
        if (dp.count(key)) return dp[key];
        if (w1.size() == 0) return w2.size();
        if (w2.size() == 0) return w1.size();
        if (w1[0] == w2[0]) {
            return minDistance(tail(w1), tail(w2));
        }
        int a = minDistance(tail(w1), w2);
        int b = minDistance(w1, tail(w2));
        int c = minDistance(tail(w1), tail(w2));

        int res = 1 + min(a, min(b, c));
        dp[key] = res;
        return res;
    }
};