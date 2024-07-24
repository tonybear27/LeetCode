class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int begin = 0;
        int ma = 0;
        int current = 0;

        for(int i = 0; i < customers.size(); i++) {
            if(!grumpy[i]) begin += customers[i];
            else if(i < minutes) current += customers[i];
        }

        ma = current;

        for(int i = minutes; i < customers.size(); i++) {
            current += customers[i] * grumpy[i];
            current -= customers[i - minutes] * grumpy[i - minutes];
            ma = max(ma, current);
        }

        return begin + ma;
    }
};