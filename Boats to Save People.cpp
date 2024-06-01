class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int freq[30001] = {0};
        int maxW = 0, minW = 30001;

        for(const auto &it: people) {
            freq[it]++;
            maxW = max(maxW, it);
            minW = min(minW, it);
        }

        for(int i = minW, j = 0; i <= maxW; i++) {
            int f = freq[i];
            fill(people.begin() + j, people.begin() + j + f, i);
            j += f;
        }

        int cnt = 0;
        for(int left = 0, right = people.size() - 1; left <= right; right--) {
            cnt++;

            if(people[left] + people[right] <= limit) left++;
        }

        return cnt;
    }
};