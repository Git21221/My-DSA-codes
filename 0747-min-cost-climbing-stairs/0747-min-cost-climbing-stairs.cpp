class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(rec(0, cost, dp), rec(1, cost, dp));
    }
    int rec(int ind, vector<int>& nums, vector<int>& dp){
        if(ind == nums.size() - 1 || ind == nums.size() - 2) return nums[ind];
        if(dp[ind] == -1){
            dp[ind] = nums[ind] + min(rec(ind + 1, nums, dp), rec(ind + 2, nums, dp));
        }
        return dp[ind];
    }
};