class Solution {
public:
    bool isMatch(string s, string p) {
        if(p == ".*") return 1;

        int n = s.length(), m = p.length();
        vector<vector<bool> > dp(n + 1, vector<bool>(m + 1, 0));
        dp[0][0] = 1;

        for(int i = 0; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j - 1] == '*') dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }

        return dp[n][m];
    }
};