class Solution {
public:
    vector<int> par;
    int find(int i) {
        return i == par[i] ? i: par[i] = find(par[i]);
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        par.resize(n);
        for(int i = 0;i < n; i++) par[i] = i;

        int a = find(0);
        int b = find(firstPerson);
        par[b] = a;

        sort(meetings.begin(), meetings.end(), [](auto &A, auto &B){
            return A[2] < B[2];
        });

        int M = meetings.size();
        for(int i = 0; i < M; ) {
            vector<int> ppl;

            int time = meetings[i][2];

            for( ;i < M && meetings[i][2] == time; i++) {
                int a = find(meetings[i][0]);
                int b = find(meetings[i][1]);
                par[b] = a;

                ppl.push_back(meetings[i][0]);
                ppl.push_back(meetings[i][1]);
            }

            for(int p:ppl) if(find(p) != find(0)) par[p] = p;
        }

        vector<int> res;
        for(int i = 0;i < n; i++) if(find(i) == find(0)) res.push_back(i);
        
        return res;
    }
};