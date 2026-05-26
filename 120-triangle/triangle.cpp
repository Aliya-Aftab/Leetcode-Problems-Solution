class Solution {
public:
    int n;
    int solve(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>&dp){
        if(row == n-1){
            return triangle[row][col];
        }
        if(dp[row][col]!=INT_MAX){
            return dp[row][col];
        }
        int minSum=triangle[row][col]+min(solve(triangle, row+1, col, dp), solve(triangle, row+1, col+1, dp));
        return dp[row][col] = minSum;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, INT_MAX));
        return solve(triangle, 0, 0, dp);
    }
};