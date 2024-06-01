class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = 0;
        dp[0][0][n-1]=grid[0][0]+grid[0][n-1];

        for(int i=1; i<m; i++) {
            for(int j=0; j<n; j++){
                for(int k=j+1; k<n; k++){
                    for(int x=-1; x<=1; x++){
                        for(int y=-1; y<=1; y++){
                            int nx=j+x, ny=k+y;
                            if(nx>=0 && nx<n && ny>=0 && ny<n){
                                int prev=dp[i-1][nx][ny];
                                if(prev!=-1) dp[i][j][k]=max(dp[i][j][k], prev+grid[i][j] + (j!=k? grid[i][k]:0));
                            }
                        }
                    }
                    if(ans<dp[i][j][k]) ans=dp[i][j][k];
                }
            }
        }

        return ans;
    }
};