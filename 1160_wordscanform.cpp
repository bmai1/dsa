class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt = 0;
        int freq[26] = {};
        for (char c : chars) freq[c - 'a']++;
        for (auto word : words) {
            bool valid = true;
            int wf[26] = {};
            for (auto c : word) { 
                wf[c - 'a']++;
                if (wf[c - 'a'] > freq[c - 'a']) {
                    valid = false;
                    break;
                }
            }
            if (valid) cnt += word.size();
        }
        return cnt;
    }
};