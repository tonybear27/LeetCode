class Solution {
public:
    int m, n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n || isVisited[i][j] || !grid[i][j]) return 0;

        isVisited[i][j] = 1;
        int gold = grid[i][j];

        for(int dir = 0; dir < 4; dir++) {
            int nextX = i + dx[dir];
            int nextY = j + dy[dir];

            gold = max(gold, grid[i][j] + dfs(grid, isVisited, nextX, nextY));
        }

        isVisited[i][j] = 0;
        return gold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> isVisited(m, vector<bool>(n, 0));
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(grid[i][j]) ans = max(ans, dfs(grid, isVisited, i, j));

        return ans;
    }
};