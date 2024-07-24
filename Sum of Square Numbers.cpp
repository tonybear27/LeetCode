class Solution {
public:
    bool judgeSquareSum(int c) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        long long left = 0;
        long long right = sqrt(c);

        while(left <= right) {
            long long temp = left * left + right * right;
            
            if(temp == c) return 1;
            else if(temp < c) left++;
            else right--;
        }

        return 0;
    }
};