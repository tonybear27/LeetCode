class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int max = 0;
		int tmp, length, width;
        int n = matrix.size();
        int m = matrix[0].size();

		for (int i = 0; i < n; i++) {
			int sum[200] = {0};
			for (int j = i; j < n; j++) {
				for (int k = 0; k < m; k++) {
                    if(matrix[j][k] == '1') sum[k] += 1;
					if (k == 0 || tmp != length * width){
						tmp = 0;
						length = 0;
					}

					length++;
					width = j - i + 1;
					tmp += sum[k];
					if (tmp == length * width) max = max > tmp ? max : tmp;
				}
			}
		}

        return max;
    }
};