class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = nums.size(), product = 1, cnt = 0;
        int left = 0, right = 0;

        while(right < n) {
            product *= nums[right++];
            while(left < right && product >= k) product /= nums[left++];

            cnt += (right - left);

        }

        return cnt;
    }
};