class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string ans;
        // find shortest string in strs using lambda expression
        string s = *min_element(strs.begin(), strs.end(),
            [] (const string& s1, const string& s2) { 
                return s1.length() < s2.length(); });
    
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j < strs.size(); ++j) {
                // return if prefix doesn't match
                if (strs[j][i] != s[i]) return ans;
            }
            ans += s[i];
        }
        return ans;
    }
};