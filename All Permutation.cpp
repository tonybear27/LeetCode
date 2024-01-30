class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        int n = nums.size();
        int times = 1;
        ans.push_back(nums);

        for(int i = 1; i <= n; i++) times *= i;

        for(int k = 0; k < times - 1; k++) {
            int idx = -1;

            for(int i = n - 2; i >= 0; i--) {
                if(nums[i] < nums[i + 1]) {
                    idx = i;
                    break;
                }
            }

            for(int i = n - 1; i >= idx && idx != -1; i--) {
                if(nums[i] > nums[idx]) {
                    swap(nums[i], nums[idx]);
                    break;
                }
            }
            
            reverse(nums.begin() + idx + 1, nums.end());

            ans.push_back(nums);
        }

        return ans;
    }
};