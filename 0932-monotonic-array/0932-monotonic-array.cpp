class Solution {
private:
    bool isIncr(vector<int> &nums) {
        int i = 0, j = 1, n = nums.size();
        while(j < n) {
            if(nums[i] > nums[j]) return false;
            j++; i++;
        }
        return true;
    }
    bool isDec(vector<int> &nums) {
        int i = 0, j = 1, n = nums.size();
        while(j < n) {
            if(nums[i] < nums[j]) return false;
            j++; i++;
        }
        return true;
    }
public:
    bool isMonotonic(vector<int>& nums) {
        return (isIncr(nums) | isDec(nums));
    }
};