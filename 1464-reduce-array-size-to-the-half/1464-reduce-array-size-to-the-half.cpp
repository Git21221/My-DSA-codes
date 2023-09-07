class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m; //element and frequency
        for(int i : arr) m[i]++;
        priority_queue<int> pq;
        for(auto it : m) pq.push(it.second);
        int sum = 0, count = 0;
        while(!pq.empty()){
            int num = pq.top();
            pq.pop();
            sum += num;
            count++;
            if(sum >= n / 2) break;
        }
        return count;
    }
};