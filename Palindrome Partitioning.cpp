class Solution {
public:
    vector<vector<string>> res;
    bool isPal(string s, int left, int right) {
        while(left < right) if(s[left++] != s[right--]) return 0;

        return 1;
    }

    void backtracking(vector<string>& temp, string& s, int i) {
        if(i == s.length()) {
            res.push_back(temp);
            return;
        }

        for(int idx = i + 1; idx <= s.length(); idx++) {
            if(isPal(s, i, idx - 1)) {
                temp.push_back(s.substr(i, idx - i));
                backtracking(temp, s, idx);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        backtracking(temp, s, 0);
        return res;      
    }
};