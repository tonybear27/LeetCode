class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
       int len = nums.size();
       vector<int> ans(len);

       int prefix = 1;
       for(int i = 0; i < len; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
       }

       int suffix = 1;
       for(int i = len - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
       }

       return ans;
    }
};