class Solution {
public:
    unordered_map<int, vector<int>> prime2idx;
    unordered_map<int, vector<int>> idx2prime;

    void dfs(int idx, vector<bool>& isVisited, unordered_map<int, bool>& mp) {
        if(isVisited[idx]) return;
        isVisited[idx] = 1;

        for(const auto &p: idx2prime[idx]) {
            if(mp[p]) continue;
            mp[p] = 1;

            for(const auto& i: prime2idx[p]) {
                if(isVisited[i]) continue;
                dfs(i, isVisited, mp);
            }
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            for(int j = 2; j * j <= nums[i]; j++) {
                if(num % j == 0) {
                    prime2idx[j].emplace_back(i);
                    idx2prime[i].emplace_back(j);
                    while(num % j == 0) num /= j;
                }
            }

            if(num > 1) {
                prime2idx[num].emplace_back(i);
                idx2prime[i].emplace_back(num);
            }
        }    

        vector<bool> isVisited(nums.size(), 0);
        unordered_map<int, bool> visitedPrime;
        dfs(0, isVisited, visitedPrime);

        for(const auto &it: isVisited) if(!it) return 0;

        return 1;
    }
};