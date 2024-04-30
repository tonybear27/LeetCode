class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++) dp[0][i] = grid[0][i];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int temp = INT_MAX;

                for(int k = 0; k < m; k++) {
                    if(k != j) temp = min(temp, grid[i][j] + dp[i - 1][k]);
                    dp[i][j] = temp;
                }
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < m; i++) ans = min(ans, dp[n - 1][i]);

        return ans;
    }
};