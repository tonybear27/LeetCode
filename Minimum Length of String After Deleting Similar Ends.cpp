class Solution {
public:
    int minimumLength(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int n = s.length();
        if(n == 1) return 1;

        int left = 0;
        int right = n - 1;

        while(left < right) {
            char prefix = s[left];
            char suffix = s[right];
            if(prefix != suffix) break;


            while(left < n && s[left] == prefix) left++;
            while(right > 0 && s[right] == suffix) right--;
        }   

        if (left > right) return 0;
        return right - left + 1;
    }
};