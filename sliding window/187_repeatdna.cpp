class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> dna;

        string curr = s.substr(0, 10);
        ++dna[curr];

        // fixed window size 10 to check dna sequences
        for (int i = 10; i < s.size(); ++i) {
            curr = curr.substr(1) + s[i];
            ++dna[curr];
        }
        for (auto it : dna) {
            if (it.second > 1) {
                res.push_back(it.first);
            }
        }
        
        return res;
    }
};