class Solution {
private: 
    // unordered_map<string, pair<int, vector<int>>> dp;
    // pair<int, vector<int>> r(vector<int>& sums, vector<int>& starts, int sum, int i, int k) {
    //     if (starts.size() == 3) return {sum, starts};
    //     if (i >= sums.size()) return {-1, {}};
        
    //     // using a hashmap like this takes too long...
    //     string key = to_string(i) + " " + to_string(starts.size());
    //     for (int idx : starts) key += " " + to_string(idx);
    //     if (dp.count(key)) return dp[key];

    //     auto skip = r(sums, starts, sum, i + 1, k);

    //     starts.push_back(i);
    //     auto take = r(sums, starts, sum + sums[i], i + k, k);
    //     starts.pop_back();
        
    //     return dp[key] = (skip.first > take.first) ? skip : take;
    // }

    int dp[20000][3];
    int threesome(vector<int>& sums, int cnt, int i, int k) {
        if (cnt == 3) return 0;
        if (i >= sums.size()) return cnt == 3 ? INT_MIN : 0;
        if (dp[i][cnt]) return dp[i][cnt];
      
        int skip = threesome(sums, cnt, i + 1, k);
        int take = sums[i] + threesome(sums, cnt + 1, i + k, k);

        return dp[i][cnt] = max(skip, take);
    }

    void dfs(vector<int>& sums, int cnt, int i, int k, vector<int>& res) {
        if (cnt == 3 || i >= sums.size()) return;

        int skip = threesome(sums, cnt, i + 1, k);
        int take = sums[i] + threesome(sums, cnt + 1, i + k, k);

        if (skip <= take) {
            res.push_back(i);
            dfs(sums, cnt + 1, i + k, k, res);
        }
        else {
            dfs(sums, cnt, i + 1, k, res);
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        vector<int> sums(n - k + 1);
        vector<int> res;

        for (int i = 0; i < k; ++i) sum += nums[i];
        sums[0] = sum;

        for (int i = k; i < n; ++i) {
            sum += nums[i] - nums[i - k];
            sums[i - k + 1] = sum;
        }

        // vector<int> starts;
        // auto p = r(sums, starts, 0, 0, k);
        // return p.second;

        threesome(sums, 0, 0, k);
        dfs(sums, 0, 0, k, res);

        return res;
    }
};
