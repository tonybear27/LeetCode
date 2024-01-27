class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> hash;

        for(const auto &s: magazine) hash[s]++;

        for(const auto &s: ransomNote) {
            if(hash.count(s) && hash[s] != 0) hash[s]--;
            else return 0;
        }

        return 1;
    }
};