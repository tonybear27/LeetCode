class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int hash[100001] = {0};

        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
            if(hash[nums[i]] > 1) return nums[i];
        }

        return -1;
    }
};