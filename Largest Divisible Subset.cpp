class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = nums.size(), maxIdx = 1, num = -1;
        vector<int> ans;
        vector<int> dp(n, 1);

        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    if(maxIdx < dp[i]) maxIdx = dp[i];
                }
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            if(maxIdx == dp[i] && (num == -1 || num % nums[i] == 0)) {
                ans.push_back(nums[i]);
                maxIdx--;
                num = nums[i];
            }
        }

        return ans;
    }
};