class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[150] = {0}, ans = 0;

        for(const auto &it: s) {
            for(int j = it - k; j <= it + k; j++) dp[it] = max(dp[it], dp[j]);

            ans = max(ans, ++dp[it]);
        }

        return ans;
    }
};