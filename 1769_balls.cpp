class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size()); 
        for (int i = 0; i < boxes.size(); ++i) {
            int operations = 0;
            for (int j = 0; j < boxes.size(); ++j) {
                // ith container
                if (i == j) { continue; }
                if (boxes[j] == '1') {
                    operations += abs(j - i);
                }
            }
            ans[i] = operations;
        }
        return ans; 
    }
};
