class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<vector<int>>& ancestor, int idx, int cur) {
        for(const auto &it: ancestor[cur]) {
            if(ans[it].empty() || ans[it].back() != idx) {
                ans[it].push_back(idx);
                dfs(ans, ancestor, idx, it);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<vector<int>> ancestor(n);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            ancestor[u].push_back(v);
        }

        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++) dfs(ans, ancestor, i, i);

        return ans;
    }
};