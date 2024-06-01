class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        sort(happiness.rbegin(), happiness.rend());

        int idx = 0;
        long long ans = 0;

        for(int i = 0; i < k; i++) {
            happiness[idx] = max(happiness[idx] - idx, 0);
            ans += happiness[idx++];
        }

        return ans;
    }
};