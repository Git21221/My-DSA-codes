class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> pattern;
        int lastSmallNum = INT_MIN;
        for(int i = nums.size()-1; i >= 0; i--) {
            if(nums[i] < lastSmallNum) return true;
            while(!pattern.empty() && pattern.top() < nums[i]) {
                lastSmallNum = pattern.top();
                pattern.pop();
            }
            pattern.push(nums[i]);
        }
        return false;
    }
};