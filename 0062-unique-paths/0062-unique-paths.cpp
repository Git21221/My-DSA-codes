class Solution {
private:
    int recursion(int startRow, int startCol, int endRow, int endCol, vector<vector<int>> dp){
        //pruning case
        if(startRow < 0 || startCol < 0 || startRow >= endRow || startCol >= endCol) return 0;
        //base condition
        if(startRow == endRow - 1 && startCol == endCol - 1) return 1;
        //cache check
        if(dp[startRow][startCol] != -1) return dp[startRow][startCol];
        //recursive calls
        int down = recursion(startRow, startCol + 1, endRow, endCol, dp);
        int right = recursion(startRow + 1, startCol, endRow, endCol, dp);
        //save and return
        return dp[startRow][startCol] = down + right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[m - 1][i] = 1;
        }
        for(int i = 0; i < m; i++){
            dp[i][n - 1] = 1;
        }
        for(int row = m - 2; row >= 0; row--){
            for(int col = n - 2; col >= 0; col--){
                dp[row][col] = dp[row][col + 1] + dp[row + 1][col];
            }
        }
        return dp[0][0];
    }
};