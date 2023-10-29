class Solution {
int dp[2600][2600];
private:
    int rec(int ind, int prev, vector<int>& nums) {
        if(ind == nums.size()) return 0;

        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int take = 0;
        if(prev == -1 || nums[ind] > nums[prev]) take = 1 + rec(ind + 1, ind, nums);
        int ntake = rec(ind + 1, prev, nums);

        return dp[ind][prev + 1] = max(take, ntake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return rec(0, -1, nums);
    }
};