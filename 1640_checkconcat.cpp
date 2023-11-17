class Solution {
    int find(int target, vector<vector<int>>& pieces) {
        for (int piece = 0; piece < pieces.size(); ++piece) {
            for (auto n : pieces[piece]) if (n == target) return piece;
        }
        return -1;
    }
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        for (int i = 0; i < arr.size();) {
            int n = find(arr[i], pieces);
            if (n == -1) return false;
            for (int j = 0; j < pieces[n].size(); ++j) {
                if (arr[i++] != pieces[n][j]) return false;
            }
        }
        return true;
    }
};