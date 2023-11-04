class Solution {
private:
    int time = 0;
    void move(int n, vector<int>& left, vector<int>& right) {
        for (auto &num : left)  if (--num == 0) left.pop_back();
        for (auto &num : right) if (++num == n) right.pop_back();
        ++time;
    }
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // int res = 0;
        // for (int& i: left)
        //     res = max(res, i);
        // for (int& i: right)
        //     res = max(res, n - i);
        // return res;

        sort(left.rbegin(), left.rend()); 
        sort(right.begin(), right.end());
        if (!left.empty() && left.back() == 0) left.pop_back();
        if (!right.empty() && right.back() == n) right.pop_back();

        while (!left.empty() || !right.empty()) {
            move(n, left, right);

            // handle falls
            if (left.empty() && right.empty()) return time;
            if (left.empty()) return time + (n - right[0]);
            if (right.empty()) return time + left[0];

            // changes directions => ants swap location
            if (right.back() + 0.5 == left.back() - 0.5) swap(left.back(), right.back());
        }
        return time;
    }
};