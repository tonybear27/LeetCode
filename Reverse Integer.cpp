class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        bool neg = 0;
        if(x < 0) {
            neg = 1;
            x = abs(x);
        }

        while(x) {
            int n = x % 10;
            if (ans > (std::numeric_limits<int>::max() - n % 10) / 10) return 0;
            else ans = ans * 10 + n % 10;

            x /= 10;
        }

        if(neg) ans *= -1;

        return ans;
    }
};