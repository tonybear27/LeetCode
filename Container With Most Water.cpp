class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = height.size();
        int ans = 0;
        int left = 0, right = n - 1;

        while(left < right) {
            int area = min(height[left], height[right]) * (right - left);
            cout << "Area: " << area << " Left: " << left << " Right: " << right << endl;
            if (area > ans) ans = area;
            
            if(height[left] > height[right]) right--;
            else left++;

        }

        return ans;
    }
};