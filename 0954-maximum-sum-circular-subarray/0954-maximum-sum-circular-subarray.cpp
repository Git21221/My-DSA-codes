class Solution {
private:
    int kadane(vector<int>& nums){
        int n = nums.size(), sum = 0, maxi = INT_MIN;
        for(auto it : nums){
            sum += it;
            maxi = max(maxi, sum);
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int x = kadane(nums), total = 0, z = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            total += nums[i];
            nums[i] *= -1;
        }
        z = kadane(nums);
        if(total + z == 0) return x;
        return max(x, total + z);
    }
};