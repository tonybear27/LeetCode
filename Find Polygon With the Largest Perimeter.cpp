class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        sort(nums.begin(), nums.end());

        long long sum = 0;

        for(const auto &n: nums) sum += n;

        for(int i = nums.size() - 1; i >= 0; i--) {
            sum -= nums[i];
            if(sum > nums[i]) return sum + nums[i];
        }

        return -1;
    }
};