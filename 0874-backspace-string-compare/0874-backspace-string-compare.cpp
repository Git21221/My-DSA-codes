class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, st;
        int n = s.size(), m = t.size();
        for(int i = 0; i < n; i++){
            if(!ss.empty() && s[i] == '#'){
                ss.pop();
            }
            else if(s[i] != '#') ss.push(s[i]);
        }
        for(int i = 0; i < m; i++){
            if(!st.empty() && t[i] == '#'){
                st.pop();
            }
            else if(t[i] != '#') st.push(t[i]);
        }
        return ss == st;
    }
};