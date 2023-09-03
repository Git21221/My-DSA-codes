class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long maxAns = -1e17, sum = 0;
        int n = nums.size();
        map<int, int> mp;
        for(int i = 0; i < k; i++){
            mp[nums[i]]++;
            sum += nums[i];
        }
        if(mp.size() >= m) maxAns = max(maxAns, sum);
        for(int i = k; i < n; i++){
            sum += nums[i];
            sum -= nums[i - k];
            mp[nums[i - k]]--;
            if(mp[nums[i - k]] == 0) mp.erase(nums[i - k]);
            mp[nums[i]]++;
            if(mp.size() >= m){
                maxAns = max(maxAns, sum);
            }
        }
        return maxAns == -1e17 ? 0 : maxAns;
    }
};