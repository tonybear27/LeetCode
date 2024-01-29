class Solution {
public:
    vector<vector<int> > ans;

    void auxiliary(vector<int>& nums, vector<int>& v, int target, int idx) {
        if(idx == nums.size()) {
            if(target == 0) ans.push_back(v);

            return;
        }
        if(nums[idx] <= target) {
            v.push_back(nums[idx]);
            auxiliary(nums, v, target - nums[idx], idx);
            v.pop_back();
        }

        auxiliary(nums, v, target, idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        auxiliary(candidates, v, target, 0);

        return ans;    
    }
};