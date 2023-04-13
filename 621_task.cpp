class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) { return tasks.size(); }
        unordered_map<char, int> m;
        int count = 0;
        for (char task: tasks) {
            m[task]++;
            count = max(count, m[task]);
        }
        int ans = (count - 1) * (n + 1);
        for (auto it: m) { 
            if (it.second == count) { ++ans; }
        }
        return max((int)tasks.size(), ans);
        
        // int time = 0;
        // map<char, int> m;
        // for (char task: tasks) { ++m[task]; }

        // while (!m.empty()) {
        //     for (const auto & [key, value] : m) {
        //         if (value != 0) {
        //             --m[key];
        //             ++time;
        //         } 
        //         if (m[key] == 0) { m.erase(key); }
        //     }
        //     if (m.size() < n && !m.empty()) { 
        //         if (n % 2 == 0) { time += n / m.size(); }
        //         else { time += (n + 1) / m.size(); }
        //     }
        // }

        // return time;
    }
};
