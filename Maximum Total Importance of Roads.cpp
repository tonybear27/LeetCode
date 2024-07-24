class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        priority_queue<pair<int, int>> pq; /*** First = cnt, Second = Idx ***/
        vector<int> cnt(n, 0);
        vector<int> importance(n, 0);

        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            cnt[u]++;
            cnt[v]++;
        }

        int m = n;

        for(int i = 0; i < n; i++) pq.push(make_pair(cnt[i], i));
        for(int i = 0; i < n; i++) {
            auto top = pq.top();
            pq.pop();
            importance[top.second] = m--;
        }

        long long ans = 0;
        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            ans += importance[u] + importance[v];
        }

        return ans;
    }
};