class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        vector<int> merged;
        
        for(const auto x: nums1) merged.push_back(x);
        for(const auto x: nums2) merged.push_back(x);
        sort(merged.begin(), merged.end());

        double ans;
        if ((n + m)%2) 
            ans = merged[(n + m)/2];
        else
            ans = (merged[(n + m)/2 - 1] + merged[(n + m) / 2]) / 2.;
        
        return ans;
    }
};