// literally 1974

class Solution {
public:
    int minTimeToType(string word) {
        int time = 0, distance;
        for (int i = 0; i < word.size(); ++i) {
            if (i == 0) distance = abs(word[i] - 'a');
            else distance = abs(word[i] - word[i - 1]);
            if (distance > 13) distance = 26 - distance;
            time += distance + 1;
        }
        return time;
    }
};