class Solution {
public:
    int row, column;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1}; 
    string target;

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int ptr, int i, int j) {
        if(ptr == target.length()) return 1;

        if(i < 0 || j < 0 || i >= row || j >= column || visited[i][j] || target[ptr] != board[i][j]) return 0;

        visited[i][j] = 1;

        for(int r = 0; r < 4; r++) if(dfs(board, visited, ptr + 1, i + dx[r], j + dy[r])) return 1;

        visited[i][j] = 0;

        return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        row = board.size();
        column = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(column, 0));
        target = word;

        for(int i = 0; i < row; i++) for(int j = 0; j < column; j++) if (dfs(board, visited, 0, i, j)) return 1;

        return 0;
    }
};