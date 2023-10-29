class Solution {
int dp[1001][1001];
private:
    int rec(vector<int>& nums, int t, int i){
        if(t == 0) return 0;
        if(t < 0 || i >= nums.size()) return -1e9;
        if(dp[t][i] != -1) return dp[t][i];
        int take = 1 + rec(nums, t - nums[i], i + 1);
        int ntake = rec(nums, t, i + 1);
        return dp[t][i] = max(take, ntake);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return rec(nums, target, 0) < 0 ? -1 : rec(nums, target, 0);
    }
};