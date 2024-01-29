class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int N = s.length();

        for(int i = N / 2; i > 0; i--) if(!(N%i)) if(s.substr(0, N - i) == s.substr(i, N)) return 1;

        return 0;
    }
};