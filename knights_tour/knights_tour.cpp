// g++ -std=c++20 knights_tour.cpp -o knights_tour.out && ./knights_tour.out
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
        {-1, -1},
        {-1, 1},
        {1, -2},
        {1, 2},
        {2, -1},
        {2, 1},
    };

    bool isValid(int nextRow, int nextCol, int n, vector<vector<bool>>& visited) {
        return (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && !visited[nextRow][nextCol]);
    }

    void backtrack(vector<int>& currPath, vector<vector<bool>>& visited, int row, int col, int n) {
        if (currPath.size() == n * n) path = currPath;
        if (!path.empty()) return; // found valid path
        visited[row][col] = true;

        int nextRow, nextCol;
        for (auto jump : jumpOffset) {
            nextRow = row + jump.first;
            nextCol = col + jump.second;
            if (isValid(nextRow, nextCol, n, visited)) {
                currPath.push_back(nextRow * n + nextCol);
                backtrack(currPath, visited, nextRow, nextCol, n);
                visited[nextRow][nextCol] = false;
                currPath.pop_back();
            }
        }
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