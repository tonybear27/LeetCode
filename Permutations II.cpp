class Solution {
public:
    vector<vector<int> > ans;

    void auxiliary(vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        vector<bool> track(21, 0);
        for(int i = idx; i < nums.size(); i++) {
            if(track[nums[i] + 10]) continue;
            swap(nums[idx], nums[i]);
            auxiliary(nums, idx + 1);
            swap(nums[idx], nums[i]);

            track[nums[i] + 10] = 1;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        auxiliary(nums, 0);

        return ans;
    }
};