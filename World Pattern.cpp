class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        
        vector<string> v;
        string temp;
        while(ss >> temp) v.push_back(temp);

        if(v.size() != pattern.length()) return 0;

        unordered_map<char, string> hash;
        int idx = 0;
        for(const auto character: pattern) {
            if(hash.count(character) && hash[character] != v[idx]) return 0; 
            else hash[character] = v[idx++];
        }

        unordered_set<string> se;
        for(const auto& i: hash) if(!se.insert(i.second).second) return 0;

        return 1;
    }
};