class Solution {
public:
    vector<vector<int> > ans;

    void auxiliary(vector<int>& v, vector<int>& nums, int target, int idx) {
        if(target == 0) {
            ans.push_back(v);
            return;
        }

        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[i - 1]) continue;
            if(nums[i] > target) break;

            v.push_back(nums[i]);
            auxiliary(v, nums, target - nums[i], i + 1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        auxiliary(v, candidates, target, 0);
        v.clear();

        return ans;    
    }
};