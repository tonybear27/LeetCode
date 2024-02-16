class Solution {
public:
    void dfs(vector<int>& ans, long long x, int n, int k) {
        if(!n) {
            ans.emplace_back(x);
            return;
        }
        
        if((x % 10) + k < 10) dfs(ans, x * 10 + (x % 10 + k), n - 1, k);
        if((x % 10) - k >= 0 && k) dfs(ans, x * 10 + (x % 10 - k), n - 1, k);
        
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> ans;

        long long x = 0;
        for(int i = 1; i < 10; i++) dfs(ans, x * 10 + i, n - 1, k);

        return ans; 
    }
};