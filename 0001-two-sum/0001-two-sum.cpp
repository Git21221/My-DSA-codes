class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int i, j, n = nums.size();
        for(i = 0; i < n - 1; i++){
            for(j = i + 1; j < n; j++) {
                if(nums[i] + nums[j] == target){
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};