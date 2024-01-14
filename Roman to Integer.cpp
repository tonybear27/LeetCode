class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char, int> maps;

        maps['M'] = 1000;
        maps['D'] = 500;
        maps['C'] = 100;
        maps['L'] = 50;
        maps['X'] = 10;
        maps['V'] = 5;
        maps['I'] = 1;

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (maps[s[i]] < maps[s[i+1]])
                ans -= maps[s[i]];
            else
                ans += maps[s[i]];
        }

        return ans;
    }
};