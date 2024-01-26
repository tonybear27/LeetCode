class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return {};
        if(n == 1) return {to_string(nums[0])};


        vector<string> ans;

        for(int i = 0; i < n; i++) {
            int j = i;

            while(j + 1 < n && (long)nums[j+1] - (long)nums[j] == 1) j++; 

            string s = "";
            if(j > i) s = to_string(nums[i]) + "->" + to_string(nums[j]);
            else s = to_string(nums[i]);
            ans.push_back(s);

            i = j;
        }

        return ans;
    }
};