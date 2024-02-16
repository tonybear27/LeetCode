class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int hash[26] = {0};
        int n = words.size();
        if(n == 1) return 1;
        
        for(const auto &it: words) 
            for(int i = 0; i < it.size(); i++)  
                hash[it[i] - 'a']++;
        
        for(int i = 0; i < 26; i++) if(hash[i] % n != 0) return 0;

        return 1;
    }
};