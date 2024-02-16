class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        unordered_map<int, int> hash;

        for(const auto &it: arr) hash[it]++;

        vector<int> fq;

        for(const auto &it: hash) fq.emplace_back(it.second);

        sort(fq.begin(), fq.end());
        int cnt = 0;

        for(int i = 0; i < fq.size(); i++) {
            if(k > fq[i]) {
                k -= fq[i];
                fq[i] = 0;
            }
            else {
                fq[i] -= k;
                k = 0;
            }

            if(fq[i] !=0 ) cnt++;
        }

        return cnt;
    }
};