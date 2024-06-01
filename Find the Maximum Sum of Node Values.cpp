class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int cnt = 0;
        int mi = INT_MAX;
        int ma = INT_MIN;

        for (int node : nums) {
            int op = node ^ k;

            sum += node;
            
            int change = op - node;

            if (change > 0) {
                mi = min(mi, change);
                sum += change;
                cnt += 1;
            } 
            else ma = max(ma, change);
            
        }

        if (cnt % 2 == 0) return sum;

        return max(sum - mi, sum + ma);
    }
};