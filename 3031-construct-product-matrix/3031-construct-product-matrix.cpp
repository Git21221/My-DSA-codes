class Solution {
int mod = 12345;
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long mul = 1;
        vector<vector<int>> ans(n, vector<int>(m, 1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                (ans[i][j] *= mul) %= mod;
                (mul *= grid[i][j]) %= mod;
            }
        }
        mul = 1;
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                (ans[i][j] *= mul) %= mod;
                (mul *= grid[i][j]) %= mod;
            }
        }
        return ans;
    }
};