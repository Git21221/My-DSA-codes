class Solution {
public:
    int dp[1001][1001];

    bool rec(int i, int j, string &s) {
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = rec(i+1, j-1, s);
        return 0;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));

        int ans = INT_MIN, start = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(rec(i, j, s) == true) {
                    if((j-i+1) > ans) {
                        ans = j-i+1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, ans);
    }
};