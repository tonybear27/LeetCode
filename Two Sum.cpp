class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> maps;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            int complement = target - nums[i];

            if(maps.count(complement)) 
                return {maps[complement], i};
            
            maps[nums[i]] = i;
        }

        return {};
    }
};