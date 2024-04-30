class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return vector<int>{0};

        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }   

        queue<int> q;

        for(int i = 0; i < n; i++) if(degree[i] == 1) q.push(i);

        vector<int> ans;
        while(!q.empty()) {
            int size = q.size();
            ans.clear();

            while(size--) {
                int node = q.front();
                q.pop();

                ans.push_back(node);

                for(int i = 0; i < graph[node].size(); i++) {
                    degree[graph[node][i]]--;

                    if(degree[graph[node][i]] == 1) q.push(graph[node][i]);
                }
            }
        }

        return ans;
    }
};