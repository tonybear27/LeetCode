class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int size = trust.size();
        if(size == 0 && n == 1) return 1;
        if(size == 0 && n != 1) return -1;

        // vector<int> hash(n, 0);
        // vector<int> trusted(n, 0);

        vector<pair<int, int>> hash(n);
        for(int i = 0; i < size; i++) {
            hash[trust[i][1] - 1].first++;
            hash[trust[i][0] - 1].second++;
        }
        for(int i = 0; i < n; i++) if(hash[i].first == n - 1 && hash[i].second == 0) return i + 1; 

        return -1;
    }
};