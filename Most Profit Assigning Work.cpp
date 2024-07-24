class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int n = profit.size();
        int m = worker.size();
        vector<pair<int, int>> dp(n);

        for(int i = 0; i < n; i++) dp[i] = make_pair(difficulty[i], profit[i]);

        sort(dp.begin(), dp.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0;
        int idx = 0;
        int best = 0;

        for(int i = 0; i < m; i++) {
            while(idx < n && worker[i] >= dp[idx].first) {
                best = max(best, dp[idx].second);
                idx++;
            }
            
            maxProfit += best;
        }

        return maxProfit;
    }
};