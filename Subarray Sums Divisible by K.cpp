class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> mp(k, 0);
        mp[0] = 1;

        int cnt = 0;
        int prefix = 0;

        for(int num: nums) {
            prefix += num;
            int n = (prefix % k + k) % k;
            cnt += mp[n]++;
        }

        return cnt;
    }
};