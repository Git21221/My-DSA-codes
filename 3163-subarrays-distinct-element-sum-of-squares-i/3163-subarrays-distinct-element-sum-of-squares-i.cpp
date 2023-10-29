class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                set<int> s;
                for(int k = i; k <= j; k++) {
                    s.insert(nums[k]);
                }
                ans += (s.size()*s.size());
            }          
        }
        return ans;
    }
};