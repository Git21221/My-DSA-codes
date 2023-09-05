class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>preSum;
        preSum[0]++;
        int sum=0,cnt=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            cnt += preSum[sum-k];
            preSum[sum]++;
            
        }
        return cnt;
    }
};