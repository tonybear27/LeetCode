class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0, right = nums.size() - 1;
        
        while(left <= right) {
            int mid = (left + right) / 2;

            
            if(nums[mid] == target) return mid;
            
            // pivot is at the right
            if(nums[mid] > nums[nums.size() - 1])
                if(target > nums[mid] || target < nums[0]) 
                    left = mid + 1;
                else
                    right = mid - 1;
            // pivot is at the left
            else 
                if(target < nums[mid] || target > nums[nums.size() - 1]) 
                    right = mid - 1;
                else
                    left = mid + 1;
        }

        return -1;
    }
};