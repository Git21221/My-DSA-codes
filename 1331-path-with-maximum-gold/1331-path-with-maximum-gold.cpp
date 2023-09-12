class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &vis, int ans, int &res){
        int m = grid.size(), n = grid[0].size();
        vis[row][col] = 1;
        res = max(res, ans);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol])
                dfs(nrow, ncol, grid, vis, ans + grid[nrow][ncol], res);
        }
        vis[row][col] = 0;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){
                    dfs(i, j, grid, vis, grid[i][j], res);
                }
            }
        }
        return res;
    }
};