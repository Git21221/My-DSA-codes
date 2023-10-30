class Solution {
typedef long long ll;
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size(), m = nums2.size(), sum1 = 0, zero1 = 0, sum2 = 0, zero2 = 0;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            if(nums1[i] != 0) sum1 += nums1[i];
            else zero1++;
        }
        for(int i = 0; i < m; i++){
            if(nums2[i] != 0) sum2 += nums2[i];
            else zero2++;
        }
        if(zero1 == 0 && sum1 < sum2 + zero2) return -1;
        if(zero2 == 0 && sum2 < sum1 + zero1) return -1;
        return max(sum1+zero1, sum2+zero2);
    }
};