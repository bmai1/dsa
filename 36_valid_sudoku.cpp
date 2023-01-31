class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // first pair <number, column>, occurences
        // rows
        map<char, int> r;
        // column
        map<pair<char, int>, int> c;
        for (auto row : board) {
            for (int i = 0; i < 9; ++i) {
                // increment num, col pair 
                if (row[i] != '.') {
                    r[row[i]]++;
                    c[{row[i], i}]++; 
                }
                if (r[row[i]] > 1 || c[{row[i], i}] > 1) { return false; }
                
            }
            r.clear();
        }

        map<char, int> box;
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        // cout << board[i + k][j + l];
                        if (board[i + k][j + l] != '.') {
                            box[board[i + k][j + l]]++;
                            if (box[board[i+k][j+l]] > 1) { return false; }
                        }
                    }
                    // each row of 3x3 
                }
                // seperate 3x3 boxes
                // cout << "\n";
                box.clear();
            }
        }
        return true; 
    }
};
