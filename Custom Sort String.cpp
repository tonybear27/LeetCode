class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for(const auto &it: order) mp[it] = 0;

        for(const auto &it: s) if(mp.find(it) != mp.end()) mp[it]++;
    
        string ans;

        for(const auto &it: order) ans.append(mp[it], it);

        for(const auto &it: s) if(mp.find(it) == mp.end()) ans.push_back(it);

        return ans;
    }
};