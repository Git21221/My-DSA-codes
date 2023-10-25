class Solution {
const int mod = 1e9 + 7;
private:
    int rec(int s, int e, int k, int steps, vector<vector<int>>& dp){
        if(steps == k){
            if(s == e) return 1;
            else return 0;
        }
        //cache check
        if(dp[s + 1001][steps] != -1) return dp[s + 1001][steps];
        int left = rec(s - 1, e, k, steps + 1, dp) % mod;
        int right = rec(s + 1, e, k, steps + 1, dp) % mod;
        return dp[s + 1001][steps] = (left + right) % mod;
    }
public:
    int numberOfWays(int s, int e, int k) {
        vector<vector<int>> dp(3001, vector<int>(1001, -1));
        return rec(s, e, k, 0, dp);
    }
};