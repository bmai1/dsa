class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int start = 0, end = height.size() - 1;
        while (start < end) {
            int h = min(height[start], height[end]);
            water = max(water, (end - start) * h);
            // move pointers to match start to min height
            while (height[start] <= h && start < end) start++;
            while (height[end] <= h && start < end) end--;
        }
        return water; 
    }
};