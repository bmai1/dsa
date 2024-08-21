class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        // simulate circle
        colors.push_back(colors[0]);
        colors.push_back(colors[1]);

        int res = 0, curr = 1;
        for (int i = 1; i < colors.size() - 1; ++i) {
            res += colors[i] != colors[i - 1] && colors[i] != colors[i + 1];
        }
        return res;
    }
};