class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), goal = n - 1;
        
        if(n == 1) return 0;

        int range = 0, idx = 0, cnt = 0;
        
        for(int i = 0; i < n; i++) {
            range = max(i + nums[i], range);
            // cout << range << endl;
            if(i == idx) {
                idx = range;
                cnt++;
                
                if(range >= goal) break;
            }
        }

        return cnt;
    }
};