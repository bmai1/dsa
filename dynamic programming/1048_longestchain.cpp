
// legit kms
// class Solution {
// private:
//     int ans = 0;
//     map<int, vector<string>> m;
//     bool insert(const string& a, const string& b) {
//         for (int i = 0; i < a.size(); ++i) {
//             if (a[i] != b[i]) {
//                 return a.substr(0, i) + a.substr(i + 1) == b;
//             }
//         }
//         return false;
//     }
//     void tr(int chain, int length, string s) {
//         for (auto word : m[length + 1]) {
//             if (insert(word, s)) {
//                 tr(chain + 1, length + 1, word);
//             }
//         }
//         ans = max(ans, chain);
//     }
// public:
//     int longestStrChain(vector<string>& words) {
//         for (auto word : words) {
//             m[word.size()].push_back(word);
//         }
//         for (auto it : m) {
//             for (auto word : it.second) {
//                 tr(1, it.first, word);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
private:
    unordered_map<string, int> dp;
    int dfs(string& word, unordered_set<string>& wordSet) {
        if (dp.find(word) != dp.end()) return dp[word];
        int chain = 1;
        for (int i = 0; i < word.size(); ++i) {
            string next = word.substr(0, i) + word.substr(i + 1);
            if (wordSet.find(next) != wordSet.end()) {
                chain = max(chain, 1 + dfs(next, wordSet));
            }
        }
        dp[word] = chain;
        return chain;
    }
public:
    int longestStrChain(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        int chain = 1;
        for (auto word : words) {
            chain = max(chain, dfs(word, wordSet));
        }
        return chain;
    }
};