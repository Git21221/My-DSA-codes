class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}}); //diff, row, col
        vector<vector<int>>dist (n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        while(!pq.empty()){
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n - 1 && col == m - 1) return diff;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++){
                int newRow = row + dr[i];
                int newCol = col + dc[i];
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m){
                    int newDiff = max(diff, abs(heights[row][col] - heights[newRow][newCol]));
                    if(dist[newRow][newCol] > newDiff){
                        dist[newRow][newCol] = newDiff;
                        pq.push({newDiff, {newRow, newCol}});
                    }
                }
            }
        }
        return 0;
    }
};