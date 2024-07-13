class Solution {
private:
    vector<string> res;
    void b(int n, string curr) {
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }
        if (curr.back() != '0') b(n, curr + "0");
        b(n, curr + "1");
    }
public:
    vector<string> validStrings(int n) {
        b(n, "0");
        b(n, "1");
        return res;
    }
};