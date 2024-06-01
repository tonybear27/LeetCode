class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> sum(n + 1, 0);

        for(int i = 0; i < n; i++) sum[i + 1] += sum[i] + abs(s[i] - t[i]);

        int left = 0, len = 0;
        int right;

        for(right = 0; right < n; right++) {
            int cost = sum[right + 1] - sum[left];

            while(cost > maxCost) cost = sum[right + 1] - sum[++left];

            len = max(len, right - left + 1);
        }

        return len;
    }
};