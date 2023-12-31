class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1] && (i - count) % 2 == 0) count++;
        }
        return (nums.size() - count) % 2 == 0 ? count : count + 1;
    }
};