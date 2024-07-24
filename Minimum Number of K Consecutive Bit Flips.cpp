class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flipped = 0;
        int ans = 0;
        vector<int> flip(n, 0);

        for(int i = 0; i < n; i++) {
            if(i >= k) flipped ^= flip[i - k];

            if(flipped == nums[i]) {
                if(i + k > n) return -1;

                flip[i] = 1;
                flipped ^= 1;
                ans++;
            }
        }

        return ans;
    }
};