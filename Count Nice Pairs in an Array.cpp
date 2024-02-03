class Solution {
public:
    int rev(int n) {
        int ans = 0;
        while(n) {
            ans = ans* 10 + n % 10;
            n /= 10;
        }

        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        unordered_map<int, long long> mp;

        long long cnt = 0, m = 1e9+7;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i] - rev(nums[i]);
            cnt = (cnt + mp[num]) % m;
            mp[num]++;
        }

        return cnt;
    }
};