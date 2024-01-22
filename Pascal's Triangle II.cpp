class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int> > ans;
        ans.push_back({1});
        ans.push_back({1, 1});
        
        int idx = 1;
        for(int r = 2; r <= numRows; r++) {
            vector<int> tmp;
            tmp.push_back(1);

            int index = 0;
            for(int i = 0; i < ans[idx].size() - 1; i++) {
                int num1 = ans[idx][i];
                int num2 = ans[idx][i + 1];
                tmp.push_back(num1 + num2);
            }
            
            tmp.push_back(1);
            idx++;

            ans.push_back(tmp);
        }

        return ans;
    }

    vector<int> getRow(int rowIndex) {

        vector<vector<int> > ans = generate(rowIndex);    
        
        vector<int> temp;
        cout << ans[rowIndex].size();
        for(int i = 0; i < ans[rowIndex].size(); i++) temp.push_back(ans[rowIndex][i]); 

        return temp;
    }
};