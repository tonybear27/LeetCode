class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int miss = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= 0) continue;
            if(nums[i] != miss) break;
            miss++;
        }

        return miss;
    }
};