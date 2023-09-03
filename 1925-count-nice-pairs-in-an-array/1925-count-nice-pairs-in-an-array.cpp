class Solution {
const int mod = 1e9 + 7;
private:
    int rev(int num){
        int ans = 0;
        while(num){
            ans = (ans * 10) + (num % 10);
            num /= 10;
        }
        return ans; 
    }
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        long long count = 0;
        for(int i = 0; i < n; i++){
            int diff = 0;
            diff = nums[i] - rev(nums[i]);
            if(m.find(diff) != m.end()) count += m[diff];
            m[diff]++;
        }
        return count % mod;
    }
};