class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        sort(m.begin(), m.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
    
        int res = m[0][0] - 1, i = 0;
        while (i < m.size()) {
            int start = m[i][0], end = m[i][1];
            int j = i + 1;
            while (j < m.size() && m[j][0] >= start && m[j][0] <= end) {
                end = max(end, m[j++][1]);
            }
            if (j == m.size()) res += days - end; // leftover
            else res += m[j][0] - end - 1; // minus one due to inclusiveness
            i = j;

            // cout << start << ' ' << end << endl;
        }
        return res;
    }
};