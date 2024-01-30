class Solution {
public:
    int auxiliary(vector<vector<int> >& dp, vector<vector<int>>& grid, int m, int n) {
        if(m < 0 || n < 0) return INT_MAX;

        if(m == 0 && n == 0) return grid[0][0];
        if(dp[m][n] != -1) return dp[m][n];

        return dp[m][n] = grid[m][n] + min(auxiliary(dp, grid, m - 1, n), auxiliary(dp, grid, m, n - 1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, -1));
        
        return auxiliary(dp, grid, m - 1, n - 1);
    }
};