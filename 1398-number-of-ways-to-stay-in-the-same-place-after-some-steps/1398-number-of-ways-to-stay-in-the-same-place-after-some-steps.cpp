class Solution {
const int mod = 1e9 + 7;
private:
    int rec(int steps, int n, int s, int e, int step, vector<vector<int>> &dp){
        if(s < 0 || s >= n) return 0;
        if(step == steps) {
            if(s == e) return 1;
            else return 0;
        }
        if(dp[s][step] != -1) return dp[s][step];
        int left = rec(steps, n, s - 1, e, step + 1, dp) % mod;
        int right = rec(steps, n, s + 1, e, step + 1, dp) % mod;
        int stay = rec(steps, n, s, e, step + 1, dp) % mod;
        int ways = (((left + right) % mod) + stay) % mod;
        return dp[s][step] = ways;
    }
public:
    int numWays(int steps, int n) {
        vector<vector<int>> dp(501, vector<int>(501, -1));
        return rec(steps, n, 0, 0, 0, dp);
    }
};