class Solution {
public:
    string licenseKeyFormatting(string s, int k) {

        string ans = "";
        int cnt = 0, len = s.size();

        for(int i = len - 1; i >= 0; i--) {
            if(s[i] != '-') {
                ans += toupper(s[i]);
                cnt++;
                if(cnt == k) {
                    cnt = 0;
                    ans += "-";
                }
            }
        }

        if(ans.size() && ans.back() == '-') ans.pop_back();

        reverse(ans.begin(), ans.end());

        return ans;
    }
};