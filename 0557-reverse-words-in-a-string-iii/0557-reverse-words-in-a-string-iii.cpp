class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<char> st;
        string ans;
        for(int i = 0; i < n; i++){
            if(s[i] != ' '){
                st.push(s[i]);
            }
            else{
                while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
                ans.push_back(' ');
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};