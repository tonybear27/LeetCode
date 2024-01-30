class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;

        unordered_map<string, vector<string> > group;

        for(int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());

            group[temp].push_back(strs[i]);
        }

        unordered_map<string, vector<string> >::iterator it;
        for(it = group.begin(); it != group.end(); it++) {
            vector<string> temp;
            for(int i = 0; i < it->second.size(); i++) 
                temp.push_back(it->second[i]);
            ans.push_back(temp);
        }

        return ans;
    }
};