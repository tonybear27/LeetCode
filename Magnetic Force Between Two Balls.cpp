class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 0;
        int right = (position[position.size() - 1] - position[0]) / (m - 1);

        int ans;

        while(left <= right) {
            int mid = (left + right) / 2;

            if(legal(position, mid, m)) {
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }

        return ans;
    }

    bool legal(vector<int>& position, int dist, int m) {
        int cnt = 1;
        int cur = position[0];

        for(int i = 1; i < position.size(); i++) {
            if(position[i] - cur >= dist) {
                cnt++;
                cur = position[i];
            }
            
            if(cnt >= m) return true;
        }

        return false;
    }
};