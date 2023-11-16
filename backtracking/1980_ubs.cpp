class Solution {
private:
    unordered_set<string> bs;
    void bt(string& perm, string& res, int n) {
        if (perm.size() == n && bs.count(perm) == 0) {
            res = perm;
            return;
        } 
        if (perm.size() > n || !res.empty()) return; 
        perm.push_back('0');
        bt(perm, res, n);
        perm.pop_back();
        perm.push_back('1');
        bt(perm, res, n);
        perm.pop_back();
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // cantor's diagonal argument
        // string res;
        // for (int i = 0; i < nums.size(); ++i) 
        //     res += nums[i][i] == '0' ? '1' : '0';
        // return res;

        for (auto s : nums) bs.insert(s);
        string perm, res;
        bt(perm, res, nums[0].size());
        return res;
    }
};