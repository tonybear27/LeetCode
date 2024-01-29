class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {    
        int left = 0, right = nums.size() - 1;
        int idx = -1;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                idx = mid;
                break;
            } 
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        
        if(idx == -1) return {-1, -1};

        int start = idx, end = idx;
        // while((nums[start] == target || nums[end] == target) && start >= 0 && end <= nums.size() - 1) {
            
        // }

        for(; start >= 0 && nums[start] == target ; start--) {}
        for(; end < nums.size() && nums[end] == target; end++) {}

        return {start + 1, end - 1};
    }
};