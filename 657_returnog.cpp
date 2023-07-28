int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
	}();

class Solution {
public:
    bool judgeCircle(string moves) {
        int c[4] = {0,0,0,0};
        for (auto m : moves) ++c[m % 5];
        return c[0] == c[3] && c[1] == c[2];

        int v = 0, h = 0;
        for (char c : moves) {
            if (c == 'U') ++v;
            else if (c == 'D') --v;
            else if (c == 'L') --h;
            else if (c == 'R') ++h;
        }
        return v == 0 && h == 0;

        unordered_map<char, int> m;
        for (char move : moves) m[move]++;
        return m['L'] == m['R'] && m['U'] == m['D'];
    }
};