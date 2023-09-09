class Solution {
private: 
int solve(vector<int>& nums, int target, vector<int> &dp){
        int way = 0;
        if(target == 0){
            return 1;
        }
        if(target < 0) return 0;
        if(dp[target] != -1) return dp[target];
        for(int i = 0; i < nums.size(); i++){
            way += solve(nums, target - nums[i], dp);
        }
        return dp[target] = way;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};