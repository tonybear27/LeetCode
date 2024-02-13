class Solution {
public:
    int countSubstrings(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        int ans = 0;

        for(int len = 1; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                if(s[i] == s[i + len - 1] && (len <= 2 || dp[i + 1][i + len - 2])) {
                    dp[i][i + len - 1] = 1;
                    ans++;
                }
            }
        }

        return ans;
    }
};