class Solution {
public:
    string minRemoveToMakeValid(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        stack<pair<char, int>> st;
        vector<bool> invalid(s.length(), 0);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') st.push({'(', i});
            if(s[i] == ')') {
                if(!st.empty() && st.top().first == '(') st.pop();
                else invalid[i] = 1;
            }
        }

        while(!st.empty()) {
            int idx = st.top().second;
            invalid[idx] = 1;
            st.pop();
        }

        string ans;
        for(int i = 0; i < s.length(); i++) if(!invalid[i]) ans += s[i];

        return ans;
    }
};