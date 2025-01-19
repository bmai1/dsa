class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int i = events[0][0], time = events[0][1];
        for (int j = 0; j < events.size() - 1; ++j) {
            int next = events[j + 1][1] - events[j][1];
            if (next > time || (next == time && events[j + 1][0] < i)) {
                time = next;
                i = events[j + 1][0];
            }
        }
        return i;
    }
};
