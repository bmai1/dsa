class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rC, int cC) {
        vector<pair<int, pair<int, int>>> d;
        vector<vector<int>> mat;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // pair<int, pair<int, int>> = {distance, {row, col}}
                d.push_back({abs(rC - i) + abs(cC - j), {i, j}});
            }
        }

        sort(d.begin(), d.end(), [](pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
            return a.first < b.first;
        });

        // convert back to vectors of size 2
        for (int i = 0; i < d.size(); ++i) {
            mat.push_back({d[i].second.first, d[i].second.second});
        }
        
        return mat;
    }
};