class Solution {
private:
    vector<int> form(vector<int> freq, vector<int>& word) {
        for (int i = 0; i < 26; ++i) {
            if (word[i] > freq[i]) return {};
            freq[i] -= word[i];
        }
        return freq;
    }
    int re(vector<string>& words, vector<int>& scores, vector<int>& freq, int i) {
        if (i == scores.size()) return 0;
        vector<int> word(26);
        for (char c : words[i]) word[c - 'a']++;
        vector<int> new_freq = form(freq, word);

        int skip = re(words, scores, freq, i + 1);
        // couldn't form new word
        if (new_freq.empty()) return skip;

        int form = scores[i] + re(words, scores, new_freq, i + 1);

        return max(skip, form);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26);
        for (char c : letters) freq[c - 'a']++;

        int n = words.size();
        vector<int> scores(n);

        for (int i = 0; i < n; ++i) {
            for (char c : words[i]) {
                scores[i] += score[c - 'a'];
            }
        }

        return re(words, scores, freq, 0);
    }
};