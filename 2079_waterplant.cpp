class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int curr = capacity, steps = 0;
        for (int i = 0; i < plants.size(); ++i) {
            // walk back to river
            if (plants[i] > curr) {
                steps += 2 * i;
                curr = capacity;
            }   
            ++steps;
            curr -= plants[i];
        }
        return steps;
    }
};