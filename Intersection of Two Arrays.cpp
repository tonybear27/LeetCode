class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int ptr1 = 0, ptr2 = 0;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;

        while(ptr1 < len1 && ptr2 < len2) {
            if(nums1[ptr1] < nums2[ptr2]) ptr1++;
            else if(nums1[ptr1] == nums2[ptr2]) {
                ans.push_back(nums1[ptr1]);
                ptr1++;
                ptr2++;
            }
            else ptr2++;
        }

        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};