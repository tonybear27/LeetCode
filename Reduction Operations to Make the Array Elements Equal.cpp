class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int hash[50001] = {0};
        int mi = INT_MAX, ma = INT_MIN;

        for(const auto &x: nums) {
            hash[x]++;
            mi = min(mi, x);
            ma = max(ma, x);
        }

        int sum = 0, temp = 0;
        for(int i = ma; i > mi; i--) {
            if(hash[i] > 0) {
                temp += hash[i];
                sum += temp;
            }
        }

        return sum;
    }
};