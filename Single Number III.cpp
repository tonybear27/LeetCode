class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) sum ^= nums[i];

        int start = 0;
        while(((sum >> start) & 1) == 0) start++;

        int first = 0, second = 0;

        for(int &x: nums) if(((x >> start) & 1 ) == 0) first ^= x; else second ^= x; 
    
        return {first, second};
    }
};