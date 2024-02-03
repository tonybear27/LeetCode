class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int N = arr.size();

        vector<int> dp(k + 1, 0);

        for(int i = N - 1; i >= 0; i--) {
            int cur = 0;
            int end = min(N, i + k);

            for(int j = i; j < end; j++) {
                cur = max(cur, arr[j]);
                dp[i % (k + 1)] = max(dp[i % (k + 1)], dp[(j + 1) % (k + 1)] + cur * (j - i + 1));
            }
        }

        return dp[0];
    }
};