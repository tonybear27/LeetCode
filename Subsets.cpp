class Solution {
public:
    vector<vector<int> > ans;

    void auxiliary(vector<int>& temp, vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        auxiliary(temp, nums, idx + 1);

        temp.pop_back();
        auxiliary(temp, nums, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> v;
        auxiliary(v, nums, 0);

        return ans;    
    }
};