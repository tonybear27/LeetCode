class Solution {
public:
    int a[26], b[26], ans = 0;
    void backtracking(vector<string>& words, vector<int>& score, int idx) {
        if(idx == words.size()) {
            int sc = 0;
            for(int i = 0; i < 26; i++) {
                if(b[i] > a[i]) return;

                sc += b[i] * score[i];
            }

            ans = max(ans, sc);

            return;
        }

        backtracking(words, score, idx + 1);
        for(const auto &it: words[idx]) b[it-'a']++;
        backtracking(words, score, idx + 1);
        for(const auto &it: words[idx]) b[it-'a']--;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(const auto &it: letters) a[it-'a']++;
        backtracking(words, score, 0);

        return ans;    
    }
};