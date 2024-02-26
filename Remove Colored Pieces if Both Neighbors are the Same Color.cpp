class Solution {
public:
    bool winnerOfGame(string colors) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int players[2] = {0};
        int len = 1;
        char prev = colors[0];
        for(int i = 1; i < colors.length(); i++) {
            if(colors[i] == prev) len++;
            else len = 1;
            if(len > 2) players[colors[i] - 'A']++;
            prev = colors[i];
        }

        return players[0] > players[1];
    }
};