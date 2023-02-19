class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        vector<int> s(10, 0);
        vector<int> g(10, 0);
        
        // count bulls
        int bulls = 0, cows = 0;
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) { ++bulls; }
            else {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }
        // count cows
        for (int j = 0; j < 10; ++j) {
            if (s[j] == g[j]) { cows += g[j]; }
            // greater num occurences in secret 
            else if (s[j] > g[j]) { cows += g[j]; }
            // guess overflow
            else { cows += s[j]; }
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};
