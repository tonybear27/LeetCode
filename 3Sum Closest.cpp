class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        int ans = 0;
        int out = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return sum;

                int diff = abs(target - sum);
                if(diff <= out) {
                    out = diff;
                    ans = sum;
                }
                if(sum < target) j++;
                else k--;

            }
        }

        return ans;
    }
};