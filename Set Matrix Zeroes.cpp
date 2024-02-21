class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        map<pair<int, int>, int> mp;
        int n = matrix.size(), m = matrix[0].size();

        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(matrix[i][j] == 0) mp[{i, j}] = 1;

        for(const auto &it: mp) {
            if(it.second == 1) {
                int i = it.first.first;
                int j = it.first.second;
                for(int r = 0; r < n; r++) matrix[r][j] = 0;
                for(int c = 0; c < m; c++) matrix[i][c] = 0;
        
            }
        }
    }
};