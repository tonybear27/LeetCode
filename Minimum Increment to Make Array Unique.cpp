class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        sort(nums.begin(), nums.end());

        int cnt = 0;
        int cur = 0;

        for(const auto &it: nums) {
            cur = max(it, cur);
            cnt += (cur - it);
            cur += 1;
            
        }

        return cnt;
    }
};