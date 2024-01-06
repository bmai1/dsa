class Solution {
    int dp[50000];
    int rec(vector<vector<int>>& jobs, int job, int time) {
        if (job == jobs.size()) return 0;
        // for each job, we can either skip or take

        if (dp[job]) return dp[job];
        
        // unpack jobs vector
        int start = jobs[job][0], end = jobs[job][1], profit = jobs[job][2];

        // find next job available with binary search
        // while jobs[next][0] < end
        int lo = job + 1, hi = jobs.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (jobs[mid][0] < end) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        int next = lo;
        
        // can take next job without skipping
        if (next == job + 1) {
            return profit + rec(jobs, next, end);
        }

        // take this job and go to next available or skip
        return dp[job] = max(profit + rec(jobs, next, end), rec(jobs, job + 1, time));
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // {start, end, profit}
        vector<vector<int>> jobs;
        for (int i = 0; i < startTime.size(); ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        // sort by start time
        sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        return rec(jobs, 0, 0);
    }
};