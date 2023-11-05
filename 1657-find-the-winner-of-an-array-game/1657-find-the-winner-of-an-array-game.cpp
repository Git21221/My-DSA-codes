class Solution {
public:
    int getWinner(vector<int>& nums, int k) {
        int n = nums.size(), curr = nums[0], win = 0;
        for(int i = 1; i < n; i++){
            if(curr < nums[i]){
                curr = nums[i];
                win = 0;
            }
            if(++win == k) break;
        }
        return curr;
    }
};