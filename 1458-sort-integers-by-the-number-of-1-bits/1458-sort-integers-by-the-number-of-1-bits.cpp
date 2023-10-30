class Solution {
private:
    int setBitCount(int n){
        int count = 0;
        while(n != 0){
            if((n & 1) == 1) count++;
            n = (n >> 1);
        }
        return count;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //pair<setbit, int>;
        for(int i = 0; i < n; i++){
            int setBit = setBitCount(arr[i]);
            pq.push({setBit, arr[i]});
        }
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};