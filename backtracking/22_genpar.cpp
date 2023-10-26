class Solution {
private:
    vector<string> ans;
    void backtrack(string par, int open, int closed, int n) {
        if (open == closed && open == n) ans.push_back(par);
        if (open < n) backtrack(par + "(", open + 1, closed, n);
        if (closed < open) backtrack(par + ")", open, closed + 1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return ans;
    }
};