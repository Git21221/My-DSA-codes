#define ll long long
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        ll n = nums1.size(), res = INT_MIN, sum = 0;
        vector<vector<int>>n1n2 (n, vector<int>(2, 0));
        for(int i = 0; i < n; i++){
            n1n2[i][0] = nums2[i];
            n1n2[i][1] = nums1[i];
        }
        sort(rbegin(n1n2), rend(n1n2));
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it : n1n2){
            int sec = it[0];
            int fir = it[1];
            sum += fir;
            pq.emplace(fir);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k) {
                res = max(res, sum * sec);
            }
        }
        return res;
    }
};