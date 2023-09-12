class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (auto s : students) q.push(s);
        int cnt = 0, i = 0;
        while (!q.empty() && cnt < q.size()) {
            int pref = q.front(); q.pop();
            if (pref != sandwiches[i]) { q.push(pref); ++cnt; }
            else { cnt = 0; ++i; }
        }
        return q.size();

        // for (int i = 0; i < sandwiches.size(); ++i) {
        //     int n = 0; // detect cycle
        //     while (!q.empty()) {
        //         if (n == q.size() * 2) return q.size();
        //         int pref = q.front(); q.pop();
        //         if (pref != sandwiches[i]) { q.push(pref); ++n; }
        //         else break;
        //     }
        // }
        // return 0;
    }
};