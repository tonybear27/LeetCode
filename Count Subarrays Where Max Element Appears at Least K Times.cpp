class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int max = *max_element(nums.begin(), nums.end());
        int n = nums.size(), cnt = 0;

        long long ans = 0;

        for(int left = 0, right = 0; right < n; right++) {
            cnt += (nums[right] == max);

            while(cnt >= k) cnt -= (nums[left++] == max);

            ans += left;
        }

        return ans;
    }
};