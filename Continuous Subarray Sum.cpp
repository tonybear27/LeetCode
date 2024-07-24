class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = nums.size();
        int prefix = 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        for(int i = 0; i < n; i++) {
            prefix += nums[i];

            int re = k == 0 ? prefix: prefix % k;

            if(mp.count(re)) { 
                if(i - mp[re] > 1) return 1; 
            }
            else mp[re] = i; 
        }

        return 0;
    }
};