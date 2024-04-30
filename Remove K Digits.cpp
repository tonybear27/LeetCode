class Solution {
public:
    string removeKdigits(string num, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        string ans;

        for(const auto &it: num) {
            while(ans.size() && k && ans.back() > it) {
                k--;
                ans.pop_back();
            }

            if(ans.size() || it != '0') ans.push_back(it);
        }

        while(ans.size() && k--) ans.pop_back();

        return ans.length() == 0? "0": ans;
    }
};