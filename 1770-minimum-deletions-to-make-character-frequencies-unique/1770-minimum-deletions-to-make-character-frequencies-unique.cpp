class Solution {
public:
    int minDeletions(string s) {
        int n = s.size(), count = 0;
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        set<int> st;
        for(int i = 0; i < 26; i++) {
            while(freq[i] != 0 && st.find(freq[i]) != st.end()){
                freq[i]--;
                count++;
            }
            st.insert(freq[i]);
        }
        return count;
    }
};