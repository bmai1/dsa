class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0, MD = 0, PD = 0, GD = 0;
        for (int i = 0; i < garbage.size(); ++i) {
            time += garbage[i].length();
            if (i > 0) {
                MD += travel[i - 1], PD += travel[i - 1], GD += travel[i - 1];
                for (char c: garbage[i]) {
                    if (c == 'M') { time += MD, MD = 0; }
                    if (c == 'P') { time += PD, PD = 0; }
                    if (c == 'G') { time += GD, GD = 0; }
                }
            }
        }
        return time;

        // int time = 0;
        // unordered_map <char, int> m; 
        // unordered_map <char, int> d;
        // for (int i = 0; i < garbage.size(); ++i) {
        //     m['M'] = 0;
        //     m['P'] = 0;
        //     m['G'] = 0;
        //     time += garbage[i].length();
        //     for (char c: garbage[i]) {
        //         m[c]++;
        //     }
        //     // travel time
        //     if (i > 0) { 
        //         for (auto it = m.begin(); it != m.end(); ++it) {
        //             d[it->first] += travel[i - 1];
        //             if (it->second != 0) { 
        //                 time += d[it->first];
        //                 d[it->first] = 0;
        //             }
        //         }
        //     }
        // }
        // return time;
    }
};
