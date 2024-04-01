class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int prefix = 0;
        int len = 0;
        unordered_map<int, int> hash;

        for(int i = 0; i < n; i++) {
            prefix += nums[i] == 0 ? -1: 1;
            if(prefix == 0) len = i + 1;
            else if(hash.find(prefix) != hash.end()) len = max(len, i - hash[prefix]);
            else hash[prefix] = i;
        }

        return len;   
    }
};