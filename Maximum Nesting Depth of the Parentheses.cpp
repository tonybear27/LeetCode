class Solution {
public:
    int maxDepth(string s) {

        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int cnt1 = 0, cnt2 = 0;

            for(int j = 0; j < i; j++) {
                if(s[j] == '(') cnt1++;
                if(s[j] == ')') cnt2++;
            }

            int temp = cnt1 - cnt2;
            ans = max(ans, temp);
        }

        return ans;
    }
};