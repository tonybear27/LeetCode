class Solution {
public:
    int auxiliary(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int left = 0, right = 0;
        unordered_map<int, int> mp;

        while(right < n) {
            mp[nums[right]]++;

            while(mp.size() > k && left <= right) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) mp.erase(nums[left]);

                left++;
            }

            ans += right - left;
            right++;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return auxiliary(nums, k) - auxiliary(nums, k - 1);
    }
};