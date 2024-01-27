class Solution {
public:

    int auxiliary(int m, int n, vector<vector<int> >& dp) {
        if(!m && !n) return 1;
        if(m < 0 || n < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];

        int up = auxiliary(m - 1, n, dp);
        int left = auxiliary(m, n - 1, dp);

        return dp[m][n] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
        return auxiliary(m - 1, n - 1, dp);
    }
};