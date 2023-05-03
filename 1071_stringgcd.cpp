class Solution {
private:
    // euclidean naive gcd ?
    int euclidean(int a, int b) {
        int gcd = 0;
        int s = min(a, b);
        for (int i = s; i >= 2; --i) {
            if (a % i == 0 && b % i == 0) { return i; }
        }
        return 1;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1) ? str1.substr(0, euclidean(size(str1), size(str2))) : "";
    }
};
