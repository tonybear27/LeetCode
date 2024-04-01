class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = nums.size();
        int ans = 0;
        int left = 0, right = 0;
        unordered_map<int, int> hash;

        while(left < n && right < n) {
            hash[nums[right]]++;

            while(hash[nums[right]] > k) {
                hash[nums[left]]--;
                left++;
            }

            ans = max(right - left + 1, ans);
            right++;
        }

        return ans;
    }
};