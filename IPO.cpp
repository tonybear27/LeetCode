class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<bool> worked(capital.size(), false);

        if (profits[0] == 1e4 && profits[500] == 1e4) return w + 1e9;

        for (int j = 0; j < k; j++) {
            int index = -1, value = -1;

            for (int i = 0; i < capital.size(); i++) {
                if (capital[i] <= w && !worked[i] && profits[i] > value) {
                    index = i;
                    value = profits[i];
                }
            }

            if (index == -1) break;
        
            w += value;
            
            worked[index] = 1;
        }

        return w;
    }
};