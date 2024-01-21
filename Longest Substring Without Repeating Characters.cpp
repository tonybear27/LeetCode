class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int N = s.length();
        vector<int> table(128, -1);
        int left = 0;
        int ans = 0;

        for(int right = 0; right < N; right++) {
            if(table[s[right]] >= left) left = table[s[right]] + 1;

            table[s[right]] = right;
        
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};