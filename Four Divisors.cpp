class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            int cnt = 0;
            int tempSum = 0;
            for(int j = 1; j * j <= nums[i]; j++) {
                if(nums[i] % j == 0) {
                    if(j != nums[i] / j) {
                        tempSum = tempSum + j + nums[i] / j;
                        cnt += 2;
                    }
                    else {
                        tempSum += j;
                        cnt++;
                    }
                }
            }

            if(cnt == 4) sum += tempSum;
        }

        return sum;
    }
};