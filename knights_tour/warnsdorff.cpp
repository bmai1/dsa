// g++ -std=c++20 warnsdorff.cpp -o warnsdorff.out && ./warnsdorff.out
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<pair<int, int>> jumpOffset = {
        {-2, -1},
        {-2, 1},
        {-1, -2},
        {-1, 2},
        {1, -2},
        {1, 2},
        {2, -1},
        {2, 1},
    };

    bool isValid(int nextRow, int nextCol, int n, vector<vector<bool>>& visited) {
        return (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && !visited[nextRow][nextCol]);
    }

    // Warnsdorff's rule: implement a heuristic to always move knight to an unvisited square with minimum possible moves

    // find valid moves for given position
    int countValidMoves(int row, int col, int n, vector<vector<bool>>& visited) {
        int count = 0;
        for (auto jump : jumpOffset) {
            int nextRow = row + jump.first;
            int nextCol = col + jump.second;
            if (isValid(nextRow, nextCol, n, visited)) {
                ++count;
            }
        }
        return count;
    }

    bool backtrack(vector<int>& currPath, vector<vector<bool>>& visited, int row, int col, int n) {
        if (currPath.size() == n * n) {
            path = currPath;
            return true;
        }

        visited[row][col] = true;

        // store moves and 2d matrix indices
        vector<pair<int, pair<int, int>>> moves;
        
        for (auto jump : jumpOffset) {
            int nextRow = row + jump.first;
            int nextCol = col + jump.second;
            if (isValid(nextRow, nextCol, n, visited)) {
                int moveCount = countValidMoves(nextRow, nextCol, n, visited);
                moves.push_back({moveCount, {nextRow, nextCol}});
            }
        }

        // sort moves based on the number of valid moves from each position
        sort(moves.begin(), moves.end());

        for (auto move : moves) {
            int nextRow = move.second.first;
            int nextCol = move.second.second;

            currPath.push_back(nextRow * n + nextCol);
            if (backtrack(currPath, visited, nextRow, nextCol, n)) return true;
            currPath.pop_back();
        }
        
        // backtrack
        visited[row][col] = false; 
        return false;
    }

public:
    vector<int> knightsTour(int n) {
        if (n < 5) return {};
        vector<int> currPath = {0};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        backtrack(currPath, visited, 0, 0, n);
        return path;
    }
};

int main() {
    Solution solve;
    vector<int> res = solve.knightsTour(5);
    for (int n : res) cout << n << " ";
    cout << endl << (res.empty() ? "No valid path exists." : "A valid path has been found.") << endl; 
    return 0;
}