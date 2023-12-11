class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1, n2;
        for (auto n : nums1) n1.insert(n);
        for (auto n : nums2) n2.insert(n);
        vector<int> res(2);
        for (auto n : nums1) res[0] += n2.find(n) != n2.end();
        for (auto n : nums2) res[1] += n1.find(n) != n1.end();
        return res;
    }
};