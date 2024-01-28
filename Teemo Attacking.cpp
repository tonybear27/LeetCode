class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int total = 0;
        int pre = -1;

        for(int t: timeSeries) {
            total += duration;

            if(pre >= t) total -= abs(pre - t) + 1;
            

            pre = t + duration - 1;
        }
        
        return total;
    }
};