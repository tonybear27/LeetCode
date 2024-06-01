class Solution {
public:
    int numSteps(string s) {
        int len = s.length() - 1;
        int carry = 0;
        int count = 0;
        
        while (len > 0) {

            if (s[len] - '0' + carry == 0) {
                carry = 0;
                count++;

            } else if (s[len] - '0' + carry == 2) {
                carry = 1;
                count++;

            } else {
                carry = 1;
                count += 2;
            }
            
            len--;
        }
        

        if (carry == 1) count++;
        
        return count;
    }
};