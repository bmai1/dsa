class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // vector<pair<int, int>> jobs;
        // for (int i = 0; i < profit.size(); ++i) {
        //     jobs.push_back({profit[i], difficulty[i]});
        // }
        // sort(jobs.rbegin(), jobs.rend());
        // int res = 0;
        // for (int& w : worker) {
        //     for (auto& p: jobs) {
        //         if (w >= p.second) {
        //             res += p.first;
        //             break;
        //         }
        //     }
        // }
        // return res;

        vector<pair<int, int>> jobs;
        int n = profit.size(), res = 0, i = 0, best = 0;
        for (int j = 0; j < n; ++j) {
            jobs.push_back({difficulty[j], profit[j]});
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        for (int& w : worker) {
            while (i < n && w >= jobs[i].first) {
                best = max(best, jobs[i++].second);
            }
            res += best;
        }
        return res;
    }
};