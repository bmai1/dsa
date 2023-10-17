class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> nums; // resets when new number pushed
        vector<int> prev; 
        vector<int> store; // tracks all numbers
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] != "prev") { 
                store.push_back(stoi(words[i]));
                nums = store;
            }
            else { 
                if (nums.empty()) nums.push_back(-1);
                prev.push_back(nums.back());
                nums.pop_back();
            }
        }
        return prev;
    }
};