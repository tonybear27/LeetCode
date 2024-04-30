class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());

        if(deads.count("0000")) return -1;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        unordered_set<string> visited;
        visited.insert("0000");

        while(!q.empty()) {
            auto front = q.front();
            string current = front.first;
            q.pop();

            if(current == target) return front.second;

            for(int i = 0; i < 4; i++) {
                for(int j: {-1, 1}) {
                    int next = (current[i] - '0' + j + 10) % 10;
                    string newCombin = current;
                    newCombin[i] = '0' + next;

                    if(deads.find(newCombin) == deads.end() && visited.find(newCombin) == visited.end()) {
                        visited.insert(newCombin);
                        q.push({newCombin, front.second + 1});
                    }
                }
            }

        }
        
        return -1;
    }
};