class Solution {
private:
    vector<string> res;
    void re(string& s, vector<string>& wordDict, int i, string word, string sentence) {
        if (i == s.size()) {
            if (word.empty()) res.push_back(sentence);
            return;
        }
        word += s[i];
        if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end())  {
            // take
            re(s, wordDict, i + 1, "", sentence.empty() ? word : sentence + " " + word); 
        }
        // skip
        re(s, wordDict, i + 1, word, sentence);
        
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        re(s, wordDict, 0, "", "");
        return res;
    }  
};