class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(), apple.end(), 0), curr = 0, ans = 0;
        sort(capacity.rbegin(), capacity.rend());
        int i = 0;
        while (curr < sum) {
            curr += capacity[i++];
            ++ans;
        }
        return ans;
    }
};