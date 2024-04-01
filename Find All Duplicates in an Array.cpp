class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int hash[100001] = {0};
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
            if(hash[nums[i]] == 2) ans.push_back(nums[i]);
        }   

        return ans;
    }
};