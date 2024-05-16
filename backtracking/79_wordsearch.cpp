class Solution {
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int row, int col, int curr) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col] || board[row][col] != word[curr]) {
            return false;
        }
        if (curr == word.size() - 1) {
            return true;
        }
        
        visited[row][col] = true;
        
        // bool found = (
        //     backtrack(board, word, visited, row - 1, col, curr + 1) || 
        //     backtrack(board, word, visited, row + 1, col, curr + 1) || 
        //     backtrack(board, word, visited, row, col - 1, curr + 1) ||
        //     backtrack(board, word, visited, row, col + 1, curr + 1)
        // );

        int m = board.size();
        int n = board[0].size();
        bool found = false;
        
        for (const auto& d : dir) {
            int newRow = row + d.first;
            int newCol = col + d.second;
            
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                !visited[newRow][newCol] && board[newRow][newCol] == word[curr + 1]) {
                if (backtrack(board, visited, word, newRow, newCol, curr + 1)) {
                    found = true;
                    break;
                }
            }
        }
        
        visited[row][col] = false; // Backtrack
        
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && backtrack(board, visited, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

