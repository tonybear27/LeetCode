class Solution {
public:
    vector<string> v={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> auxiliary(vector<string> ans, char digit) {
        
        int d = digit - '0';

        string s = v[d];

        vector<string> anss;

        for(auto x: ans) {
            for (char c: s)
                anss.push_back(x + c);
        }

        return anss;
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty()) return {};

        vector<string> ans;
        ans.push_back("");

        for(char i: digits) ans = auxiliary(ans, i);

        return ans;
    }
};