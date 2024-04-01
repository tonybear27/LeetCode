class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int hash[26] = {0};

        for(const auto &it: tasks) hash[it - 'A']++;
        
        sort(begin(hash), end(hash));

        int chunk = hash[25] - 1;
        int idel = chunk * n;

        for(int i = 24; i >= 0; i--) idel -= min(hash[i], chunk);

        return idel < 0 ? tasks.size(): tasks.size() + idel;
    }
};