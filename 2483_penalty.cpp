class Solution {
public:
    int bestClosingTime(string customers) {
        int mscore = 0, score = 0, j = -1;
        for (int i = 0; i < customers.size(); ++i) {
            score += (customers[i] == 'Y') ? 1 : -1;
            if (score > mscore) {
                mscore = score;
                j = i;
            }
        }
        return j + 1;
    }
};