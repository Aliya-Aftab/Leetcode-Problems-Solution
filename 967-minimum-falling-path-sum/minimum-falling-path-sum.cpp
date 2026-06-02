class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n, vector<int>(n));
        for(int i=0; i<n ;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int left=(j-1 >=0) ? dp[i-1][j-1] : 1e9;
                int right=(j+1 < n) ? dp[i-1][j+1] : 1e9;
                int top=dp[i-1][j];
                dp[i][j]=matrix[i][j]+ min({left, right, top});
            }
        }
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            mini=min(mini, dp[n-1][i]);
        }
        return mini;
    }
};

/*
dp[i][j] = min path sum from 0,0 to cell at (i, j).
*/