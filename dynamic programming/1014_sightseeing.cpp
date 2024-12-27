class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // score = (values[i] + i) + (values[j] - j) = i_score + j_score
        // the variables are independent, maximize i_score and j_score (i < j)
        int i_score = values[0], max_score = 0;
        for (int j = 1; j < values.size(); ++j) {
            max_score = max(max_score, i_score + values[j] - j);
            i_score = max(i_score, values[j] + j);
        }
        return max_score;
    }
};
