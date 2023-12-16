// g++ -std=c++20 knights_tour.cpp -o knights_tour.out && ./knights_tour.out
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    // path is returned as an array of positions zero-indexed from left to right, top to bottom: currRow * n + currCol  
    // e.g., n = 5 should contain all positions from 0-24 in valid knight moves.
    vector<int> path; 

    // 8 possible knight moves
    vector<pair<int, int>> jumpOffset = {
        {-2, -1}, // 2 up, 1 left
        {-2, 1},  // 2 up, 1 right
        {-1, -2},  // 1 up, 2 left
        {-1, 2},  // 1 up, 2 right
        {1, -2},  // 1 down, 2 left
        {1, 2},   // 1 down, 2 right
        {2, -1},  // 2 down, 1 left
        {2, 1},   // 2 down, 1 right
    };

    // check if a move is within board boundaries and not yet visited
    bool isValid(int nextRow, int nextCol, int n, vector<vector<bool>>& visited) {
        return (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && !visited[nextRow][nextCol]);
    }

    // recursively try moves to find valid knight path
    void backtrack(vector<int>& currPath, vector<vector<bool>>& visited, int row, int col, int n) {
        
        if (!path.empty()) return; // found valid path

        currPath.push_back(row * n + col);
        visited[row][col] = true;

        if (currPath.size() == n * n) {
          path = currPath; // all squares have been visited
          return;
        }
        
        int nextRow, nextCol;
        for (auto jump : jumpOffset) {
            // find next possible positions (maximum of 8) by looping through offset array
            nextRow = row + jump.first;
            nextCol = col + jump.second;
            if (isValid(nextRow, nextCol, n, visited)) {
                backtrack(currPath, visited, nextRow, nextCol, n); // recursively test new path with current move
            }
        }
        visited[row][col] = false;
        currPath.pop_back();
    }
public:
    // solver method
    vector<int> knightsTour(int n) {
        if (n < 5) return {}; 
        vector<int> currPath;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        backtrack(currPath, visited, 0, 0, n);
        return path;
    }
};

int main() {
    Solution solve;
    vector<int> res = solve.knightsTour(8);
    for (int n : res) cout << n << " ";
    cout << endl << (res.empty() ? "No valid path exists." : "A valid path has been found.") << endl; 
    return 0;
}