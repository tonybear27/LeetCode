class Solution {
public:
    string frequencySort(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        unordered_map<char, int> mp;
        
        for(const auto &it: s) mp[it]++;
        vector<pair<char, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(), [](const auto &a, const auto &b){
            return a.second > b.second;
        });

        string ans = "";
        for(const auto it: v) {
            for(int i = 0; i < it.second; i++)
                ans += it.first;
        }

        return ans;
    }
};