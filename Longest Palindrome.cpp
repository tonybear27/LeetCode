class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char, int> hash;
        int oddcnt = 0;

        for(const auto &x: s) {
            hash[x]++;
            if(hash[x] % 2) oddcnt++;
            else oddcnt--;
        }


        if(oddcnt > 1) return s.length() - oddcnt + 1;
        return s.length();
    }
};