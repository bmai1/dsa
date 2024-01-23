class Solution {
private:
    unordered_map<string, bool> visited;
    int res = 0;
    
    bool unique(string s) {
        int a[26] = {};
        for (char c : s) {
            if (++a[c - 'a'] > 1) {
                return false;
            }
        }
        return true;
    }

    void backtrack(vector<string>& arr, string c, int i) {
        res = max(res, (int) c.size());
        for (; i < arr.size(); ++i) {
            string s = arr[i];
            if (unique(c + s) && !visited[c + s]) {
                visited[c + s] = true;
                backtrack(arr, c + s, i + 1);
                visited[c + s] = false;
            }
        }
    }

public:
    int maxLength(vector<string>& arr) {
        backtrack(arr, "", 0);
        return res;
    }
};