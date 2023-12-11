class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n); 
        vector<int> aux(n + 1);
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (++aux[A[i]] == 2) ++curr;
            if (++aux[B[i]] == 2) ++curr;
            C[i] = curr;
        }
        return C;
    }
};