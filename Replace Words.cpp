class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> s(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);
        string token, ans;
        vector<string> tokens;
        while(ss >> token) tokens.push_back(token);

        for(const auto &it: tokens) {
            int idx = 0;

            while(idx <= it.length()) {
                idx++;

                string sub = it.substr(0, idx);
                
                if(s.find(sub) != s.end()) {
                    ans += sub + " ";
                    break; 
                }
                
                if(idx == it.length()) ans += sub + " ";  
            }
        }

        ans.erase(ans.size() - 1);

        return ans;
    }
};