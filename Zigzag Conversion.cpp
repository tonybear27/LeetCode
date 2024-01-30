class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        vector<string> v(numRows, "");

        bool reach = 1;
        int current = 0;

        for(int i = 0; i < s.length(); i++) {
            if(current == 0 || current == numRows - 1) reach = !reach;
            // cout << current << endl;
            v[current] += s[i];

            if(!reach) current++;
            else current--;
        }

        string ans = "";
        for(const auto str: v) ans += str;

        return ans;
    }
};