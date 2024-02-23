class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        if(encodedText == "") return "";
        
        int n = encodedText.size();
        int columns = n / rows;
        int r = 0, cnt = 0, total = 0;
        string ans = "";

        for(const auto &it: encodedText) if(it != ' ') total++;

        while(1) {
            bool flag = 0;

            for(int i = r; i < n; i += columns + 1) {
                if(encodedText[i] != ' ') cnt++;
                ans += encodedText[i];

                if(cnt == total) {
                    flag = 1;
                    break;
                }
            }

            if(flag) break;
            r++;
        }

        return ans; 
    }
};