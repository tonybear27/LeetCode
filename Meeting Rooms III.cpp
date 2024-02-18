class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        sort(meetings.begin(), meetings.end());
        vector<int> ans(n, 0);
        vector<long long> time(n, 0);

        for(int i = 0; i < meetings.size(); i++) {

            int start = meetings[i][0];
            int end = meetings[i][1];
            int minIdx = -1;
            bool flag = 0;
            long long val = 1e18;

            for(int j = 0; j < n; j++) {

                if(time[j] < val) {
                    val = time[j];
                    minIdx = j;
                }

                if(time[j] <= start) {
                    flag = 1;
                    ans[j]++;
                    time[j] = end;
                    break;
                }
            }

            if(!flag) {
                ans[minIdx]++;
                time[minIdx] += ((long long)(end - start));
            }
            
        }
        
        int maxi = -1, id = -1;

        for(int i = 0; i < n; i++) {
            if(ans[i] > maxi) {
                maxi = ans[i];
                id = i;
            }
        }

        return id;
    }
};