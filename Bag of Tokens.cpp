class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int left = 0;
        int right = n - 1;
        int score = 0;
        int ans = 0;

        while(left <= right) {
            if(power >= tokens[left]) {
                power -= tokens[left++];
                score++;
                ans = max(ans, score);
            }
            else if(score > 0) {
                power += tokens[right--];
                score--;
            }
            else break;
        }

        return ans;
    }
};