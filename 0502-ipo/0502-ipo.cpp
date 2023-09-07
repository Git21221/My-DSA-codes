class Solution {
private:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<vector<int>> pc(n, vector<int>(2, 0));
        for(int i = 0; i < n; i++){
            pc[i][0] = profits[i];
            pc[i][1] = capital[i];
        }
        sort(rbegin(pc),rend(pc), cmp);
        priority_queue<int> pq;
        int i = 0;
        while(k--){
            while(i < n && pc[i][1] <= w){
                pq.push(pc[i][0]);
                i++;
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};