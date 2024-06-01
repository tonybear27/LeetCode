class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> exit(wordDict.begin(), wordDict.end());

        return auxiliary(exit, s, 0);
    }

    vector<string> auxiliary(unordered_set<string>& exit, string s, int idx) {
        vector<string> valid;

        if(idx == s.length()) valid.push_back("");

        for(int j = idx + 1; j <= s.length(); j++) {
            string prefix = s.substr(idx, j - idx);

            if(exit.find(prefix) != exit.end()) {
                vector<string> suffixes = auxiliary(exit, s, j);

                for(const auto &suffix: suffixes) valid.push_back(prefix + (suffix.empty()? "": " ") + suffix);
            }
        }

        return valid;
    }
};