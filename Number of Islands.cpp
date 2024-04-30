class Solution {
public:
    int row, column;
    void dfs(vector<vector<char>>& map, int i, int j) {
        if(i >= row || i < 0 || j >= column || j < 0 || map[i][j] == '0') return;

        map[i][j] = '0';

        dfs(map, i + 1, j);
        dfs(map, i - 1, j);
        dfs(map, i, j + 1);
        dfs(map, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        row = grid.size();
        column = grid[0].size();

        int cnt = 0;

        for(int i = 0; i < row; i++) 
            for(int j = 0; j < column; j++) 
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    cnt++;
                }

        return cnt;
    }
};