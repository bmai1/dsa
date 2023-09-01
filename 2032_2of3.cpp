class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> ans;
        int n1[101] {}, n2[101] {}, n3[101] {};
        for (int n : nums1) n1[n] = 1;
        for (int n : nums2) n2[n] = 1;
        for (int n : nums3) n3[n] = 1;
        for (int i = 0; i < 101; ++i) 
            if (n1[i] + n2[i] + n3[i] >= 2) ans.push_back(i);
        return ans; 
    }
};