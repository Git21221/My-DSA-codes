vector<int> prefix(10000);
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }
    int sumRange(int left, int right) {
        if(left == 0) return prefix[right];
        return prefix[right] - prefix[left - 1];
    }
};