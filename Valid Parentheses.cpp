class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '(') st.push('(');
            else if (s[i] == '{') st.push('{');
            else if (s[i] == '[') st.push('[');
            else if (s[i] == ')') {

                if (st.empty()) return 0;

                char t = st.top();
                st.pop();

                if(t != '(') return 0; 
            }
            else if (s[i] == ']') {

                if (st.empty()) return 0;
                char t = st.top();
                st.pop();

                if(t != '[') return 0;
            }
            else if (s[i] == '}') {

                if (st.empty()) return 0;
                char t = st.top();
                st.pop();

                if(t != '{') return 0;
            }
        }

        if(st.empty()) return 1;

        return 0;  
    }
};