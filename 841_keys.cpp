class Solution {
private: 
    void dfs(vector<vector<int>>& rooms, vector<bool>& unlocked, int room) {
        if (unlocked[room] == true && room != 0) { return; } 
        unlocked[room] = true; 
        for (auto key : rooms[room]) {
            // cout << key;
            dfs(rooms, unlocked, key);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> unlocked(n); 
        unlocked[0] = true;
        dfs(rooms, unlocked, 0);
        for (int i = 1; i < n; ++i) {
            if (unlocked[i] == false) { return false; }
        }
        return true; 
    }
};
