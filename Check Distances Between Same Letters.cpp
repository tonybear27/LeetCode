class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        unordered_map<char, int> hash;

        for(int i = 0; i < s.length(); i++) {
            if(hash.count(s[i])) {
                int dist = i - hash[s[i]] - 1;
                if(distance[s[i] - 'a'] != dist) return 0;
            }
            else
                hash[s[i]] = i;
        }

        return 1;
    }
};