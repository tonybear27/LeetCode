class Solution {
public:
    
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;

        int maxLen = 1;
        int start = 0, end = 0;

        vector<vector<bool> > dp(s.length(), vector<bool>(s.length(), 0));

        for(int i = 0; i < s.length(); i++) {
            dp[i][i] = 1;
            for(int j = 0; j < i; j++) {
                if(s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = 1;

                    if(i - j + 1 > maxLen) {
                        maxLen = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }

        return s.substr(start, end - start + 1);

    }
};