class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        long long res = 0;
        int bd = - 1, left = -1, right = -1;

        for(int i = 0; i < nums.size(); i++){

            if(!(minK <= nums[i] && nums[i] <= maxK)) bd = i;

            if(nums[i] == minK) left = i;

            if(nums[i] == maxK) right = i;

            res += max(0, min(left, right) - bd); 
        }

        return res;
    }
};