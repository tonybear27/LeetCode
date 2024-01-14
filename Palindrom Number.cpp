class Solution {
public:
    bool isPalindrome(int x) {

        stringstream ss;
        ss << x;

        string s = ss.str();
        string org = s;
        reverse(s.begin(), s.end());
        
        if (s == org)
            return 1;
        else
            return 0;      
    }
};