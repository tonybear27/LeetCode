class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    
        vector<pair<double, int>> ratio;
        int n = quality.size();

        for(int i = 0; i < n; i++) ratio.push_back({(double(wage[i]) / quality[i]), i});

        sort(ratio.begin(), ratio.end());
        
        priority_queue<int> heap;
        int sum = 0;
        double maxrat = 0.0;

        for(int i = 0; i < k; i++) {
            sum += quality[ratio[i].second];
            maxrat = max(maxrat, ratio[i].first);
            heap.push(quality[ratio[i].second]);
        }

        double ans = maxrat * sum;
        for(int i = k; i < n; i++) {
            maxrat = max(maxrat, ratio[i].first);
            sum -= heap.top();
            heap.pop();

            sum += quality[ratio[i].second];
            heap.push(quality[ratio[i].second]);
            ans = min(ans, maxrat * sum);
        }

        return ans;
    }
};