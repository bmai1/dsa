class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int mx = 0;
        unordered_set<int> s;

        // insert prefixes of arr1
        for (int n : arr1) {
            while (n) {
                s.insert(n);
                n /= 10;
            }
        }
        for (int n : arr2) {
            // find prefix from back
            while (n && n >= pow(10, mx)) {
                if (s.find(n) != s.end()) mx = to_string(n).size();
                n /= 10;
            }
        }
        
        return mx;
    }
};