class Solution {
public:
    string losingPlayer(int x, int y) {
        // while (true) {
        //     // alice's turn 
        //     if (!x || y < 4) return "Bob";
        //     --x; y -= 4;
        //     // bob's turn
        //     if (!x || y < 4) return "Alice";
        //     --x; y -= 4;
        // }

        for (int i = 0; i < 100; ++i) {
            if (!x || y < 4) return i % 2 == 0 ? "Bob" : "Alice";
            --x; y -= 4;
        }
        return "";
    }
};