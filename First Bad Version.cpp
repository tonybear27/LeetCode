// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long first = 0, last = n;
        
        while(first < last) {
            long long mid = (first + last) / 2;

            bool flag = isBadVersion(mid);

            if(flag) last = mid;
            else first = mid + 1;
        }

        return last;
    }
};