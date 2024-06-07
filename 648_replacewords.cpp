class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> s;
        for (auto word : dictionary) s.insert(word);

        string res, curr;
        for (int i = 0; i < sentence.size(); ++i) {
            curr += sentence[i];
            if (s.find(curr) != s.end()) {
                res += curr;
                while (i < sentence.size() && sentence[i] != ' ') ++i;
                if (i != sentence.size()) res += ' ';
                curr.clear();
            }
            if (sentence[i] == ' ' || i == sentence.size() - 1) {
                res += curr;
                curr.clear();
            }
        }
        return res;
    }
};