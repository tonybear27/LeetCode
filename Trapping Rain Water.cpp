class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int sum = 0;
        int left_max = height[0], right_max = height[right];

        while(left < right) {
            if(left_max <= right_max) {
                sum += (left_max - height[left]);
                left++;

                left_max = max(left_max, height[left]);
            }
            else {
                sum += (right_max - height[right]);
                right--;

                right_max = max(right_max, height[right]);
            }
        }

        
        return sum;
    }

};