class Solution {
public:
    int countTriplets(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = arr.size();
        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) prefix[i + 1] = prefix[i] ^ arr[i];

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int k = i + 1; k < n; k++) if(prefix[k + 1] == prefix[i]) cnt += (k - i);
        }

        return cnt;
    }
};