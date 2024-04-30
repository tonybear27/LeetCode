class Solution {
public:
    int minx, miny, maxx, maxy;
    void init() {
        minx = INT_MAX;
        miny = INT_MAX;
        maxx = INT_MIN;
        maxy = INT_MIN;
    }

    void dfs(vector<vector<int>>& land, int i, int j) {
        if(i < 0 || i >= land.size() || j < 0 || j >= land[0].size() || !land[i][j]) return;

        land[i][j] = 0;
        minx = min(i, minx);
        miny = min(j, miny);
        maxx = max(i, maxx);
        maxy = max(j, maxy);

        dfs(land, i + 1, j);
        dfs(land, i - 1, j);
        dfs(land, i, j + 1);
        dfs(land, i, j - 1);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<vector<int>> ans;
        init();

        for(int i = 0; i < land.size(); i++) {
            for(int j = 0; j < land[0].size(); j++) {
                if(land[i][j]) {
                    dfs(land, i, j);
                    vector<int> temp(4);
                    temp[0] = minx, temp[1] = miny, temp[2] = maxx, temp[3] = maxy;
                    ans.push_back(temp);
                }   

                init();
            }
        }

        return ans;
    }
};