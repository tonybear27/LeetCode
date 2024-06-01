class Solution {
public:
    int compareVersion(string version1, string version2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<string> s1, s2;
        stringstream ss(version1), sss(version2);
        string temp;

        while(getline(ss, temp, '.')) s1.push_back(temp);
        while(getline(sss, temp, '.')) s2.push_back(temp);
        
        int diff = abs(int(s1.size())- int(s2.size()));
        
        if(s1.size() < s2.size()) for(int i = 0; i < diff; i++) s1.push_back("0");
        else for(int i = 0; i < diff; i++) s2.push_back("0");

        for(int i = 0; i < s1.size(); i++) {
            int n1 = stoi(s1[i]);
            int n2 = stoi(s2[i]);
            if(n1 > n2) return 1;
            else if(n1 < n2) return -1;
        }

        
        return 0;
    }
};