class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        vector<int> rightMin(n, nums.back());
        int temp = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            if(rightMin[i] > temp){
                rightMin[i] = temp;
            }
            temp = min(temp, nums[i]);
        }
        int leftMin = nums[0];
        for(int i = 1; i < n - 1; i++){
            if(leftMin < nums[i] && nums[i] > rightMin[i]){
                ans = min(ans, (leftMin + nums[i] + rightMin[i]));
            }
            leftMin = min(nums[i], leftMin);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};