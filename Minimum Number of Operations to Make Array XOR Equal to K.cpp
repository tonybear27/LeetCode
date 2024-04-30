class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;

        for(const auto &it: nums) ans ^= it;

        ans ^= k;

        int res = 0;
        while(ans > 0) {
            if(ans & 1) res++;

            ans >>= 1;
        }

        return res;
    }
};