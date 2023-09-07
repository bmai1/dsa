class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        // this fails when it's better to shift the even start chip. 
        // int cost = 0, pos = -1;
        // for (int i = 0; i < position.size(); ++i) {
        //     if (pos == -1 && position[i]) pos = position[i]; // first chip
        //     else if ((position[i] - pos) % 2 != 0) ++cost;
        // }
        // return cost;

        // find min of odd and even
        int o = 0, e = 0;
        for (auto p : position) p % 2 ? ++e : ++o;
        return min(o, e);
    }
};