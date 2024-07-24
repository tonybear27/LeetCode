class Solution {
public:
    bool auxiliary(vector<int>& hand, int groupSize, int i, int n) {
        int next = hand[i] + 1;
        hand[i] = -1;
        
        int cnt = 1;

        i++;

        while(i < n && cnt < groupSize) {
            if(hand[i] == next) {
                next = hand[i] + 1;
                hand[i] = -1;
                cnt++;
            }
            
            i++;
        }

        return cnt == groupSize;
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());

        int n = hand.size();

        for(int i = 0; i < n; i++) if(hand[i] != -1) if(!auxiliary(hand, groupSize, i, n)) return 0;

        return 1; 
    }
};