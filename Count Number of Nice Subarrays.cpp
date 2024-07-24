class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        int ans = 0, temp = 0;
        
        for (int v : nums) {
            temp += v & 1;

            if (temp - k >= 0) ans += dp[temp - k];
            
            dp[temp]++;
        }

        return ans;
    }
};