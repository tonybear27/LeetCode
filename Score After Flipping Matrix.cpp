class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = (1 << (m - 1)) * n;

        for(int i = 1; i < m; i++) {
            int val = 1 << (m - 1 - i);
            int set = 0;

            for(int j = 0; j < n; j++) if(grid[j][i] == grid[j][0]) set++;

            ans += max(set, n - set) * val;
        }

        return ans;
    }
};