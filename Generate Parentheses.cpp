class Solution {
public:
    vector<string> ans;
    
    void dfs(string curr, int open, int close, int n) {
        if(curr.length() == n * 2) {
            ans.push_back(curr);
            return;
        }

        if(open < n) {
            curr += "(";
            dfs(curr, open + 1, close, n);
            curr.pop_back();
        }
        if(open > close) {
            curr += ")";
            dfs(curr, open, close + 1, n);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        dfs("", 0, 0, n);

        return ans;
    }
};