class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<int> pos, neg, ans;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }

        int posIdx = 0, negIdx = 0, turn = 0;
        while(posIdx < pos.size() || negIdx < neg.size()) {
            if(turn % 2 == 0) ans.push_back(pos[posIdx++]);
            else ans.push_back(neg[negIdx++]);

            turn++;
        }

        return ans;
    }
};