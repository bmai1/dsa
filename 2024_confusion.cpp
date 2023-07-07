class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // just do window twice
        int n = answerKey.size();
        int cnt = 0;
        int left = 0; 
        int maxLength = 0;
        for (int right = 0; right < n; ++right) {
            if (answerKey[right] == 'F') ++cnt;
            while (cnt > k) {
                if (answerKey[left] == 'F') --cnt;
                left++;
            }  
            maxLength = max(maxLength, right - left + 1); 
        }
        cnt = 0, left = 0;
        for (int right = 0; right < n; ++right) {
            if (answerKey[right] == 'T') ++cnt;
            while (cnt > k) {
                if (answerKey[left] == 'T') --cnt;
                left++;
            }  
            maxLength = max(maxLength, right - left + 1); 
        }
        return maxLength;
    }
};
