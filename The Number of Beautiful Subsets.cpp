class Solution {
public:
    int cnt = 0;
    unordered_map<int, int> mp;

    void backtracking(vector<int>& nums, int idx, int k) {
        if(idx == nums.size()) {
            cnt++;
            return;
        }

        int n = nums[idx];
        
        if(mp.find(n - k) == mp.end() && mp.find(n + k) == mp.end()) {
            mp[n]++;
            backtracking(nums, idx + 1, k);
            mp[n]--;

            if(mp[n] == 0) mp.erase(n);
        }

        backtracking(nums, idx + 1, k);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        backtracking(nums, 0, k);
        return cnt - 1;
    }
};