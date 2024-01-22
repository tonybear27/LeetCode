class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = INT_MAX;
        int opt = 0;

        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < mi) mi = prices[i];

            int p = prices[i] - mi;
            if (opt < p) opt = p;
        }

        return opt;
    }
};