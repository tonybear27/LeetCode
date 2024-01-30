class Solution {
public:
    string multiply(string num1, string num2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        string ans(num1.length() + num2.length(), '0');

        for(int i = num1.length() - 1; i >= 0; i--) {
            for(int j = num2.length() - 1; j >= 0; j--) {
                int num = (num1[i] - '0') * (num2[j] - '0');
                int sum = num + (ans[i + j + 1] - '0');
                ans[i + j] += sum / 10;
                ans[i + j + 1] = '0' + sum % 10;
            }
        }    

        const int it = ans.find_first_not_of('0');
        return it == string::npos ? "0" : ans.substr(it);
    }
};