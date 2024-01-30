class Solution {
public:
    vector<vector<int> > ans;

    void auxiliary(vector<int>& v, int n, int k, int idx) {
        if(v.size() == k) {
            ans.push_back(v);
            return;
        }

        for(int i = idx; i <= n; i++) {
            v.push_back(i);
            auxiliary(v, n, k, i + 1);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> v;

        auxiliary(v, n, k, 1);

        return ans;
    }
};