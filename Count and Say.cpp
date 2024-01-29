class Solution {
public:
    string auxiliary(int n) {
        if(n == 1) return "1";

        string tmp = auxiliary(n - 1);
        int cnt = 1;
        string ans = "";
        for(int i = 0; i < tmp.size() - 1; i++) {
            if(tmp[i] == tmp[i + 1]) cnt++;
            else {
                ans += to_string(cnt) + tmp[i];
                cnt = 1;
            }
        }

        return ans + to_string(cnt) + tmp[tmp.length() - 1];
    }

    string countAndSay(int n) {
        
        return auxiliary(n);
    }
};