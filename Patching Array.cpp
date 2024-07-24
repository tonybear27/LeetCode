class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int ans = 0;
        int idx = 0;

        while(miss <= n) {
            if(idx < nums.size() && nums[idx] <= miss) {
                miss += nums[idx];
                idx++;
            }
            else {
                miss += miss;
                ans++;
            }
        }

        return ans;
    }
};