class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        unordered_map<int, vector<pair<int, int>>> graph;
        for(const auto it: flights) graph[it[0]].push_back({it[1], it[2]});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;

        while(!q.empty() && stops <= k) {
            int size = q.size();

            while(size-- > 0) {
                auto it = q.front();
                q.pop();

                if(!graph.count(it.first)) continue;

                for(const auto &i: graph[it.first]) {
                    if(i.second + it.second < dist[i.first]) {
                        dist[i.first] = i.second + it.second;
                        q.push({i.first, dist[i.first]});
                    }
                }
            }

            stops++;
        }

        return dist[dst] == INT_MAX? -1: dist[dst];
    }
};