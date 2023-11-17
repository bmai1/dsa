class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> visited;
        pair<int, int> loc = {0, 0}; // {x, y}
        visited.insert(loc);
        for (auto c : path) {
            if (c == 'N') ++loc.first;
            if (c == 'S') --loc.first;
            if (c == 'E') ++loc.second;
            if (c == 'W') --loc.second;
            if (visited.count(loc) == 0) visited.insert(loc);
            else return true;
        }
        return false;
    }
};