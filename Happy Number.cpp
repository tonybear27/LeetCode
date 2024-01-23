// The use of tortoise hare algorithm

class Solution {
    long long digitSum(int n) {

        long long sum = 0;
        while(n) {
            sum += (n % 10)*(n % 10);
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        long long  firstCall = n;
        long long  nextCall = digitSum(n);

        while (firstCall != nextCall) {
            firstCall = digitSum(firstCall);
            nextCall = digitSum(digitSum(nextCall));
            if (firstCall == 1 || nextCall == 1) return true;
        }
        
        return firstCall == 1;
    }
};