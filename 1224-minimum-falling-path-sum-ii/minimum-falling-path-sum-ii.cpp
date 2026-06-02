class Solution {
public:
    int m;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&t){
        if(i == m-1){
            return grid[i][j];
        }
        if(t[i][j]!=1e9){
            return t[i][j];
        }

        int minSteps=INT_MAX;
        for(int k=0; k<m; k++){
            if(k!=j){
            minSteps=min(minSteps, solve(i+1,k, grid, t));
            }
        }
        return t[i][j]=grid[i][j] + minSteps;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
       m=grid.size();
       int mini = INT_MAX;
       vector<vector<int>>t(m, vector<int>(m, 1e9));
       for(int i=0; i<m; i++){
        mini=min(mini, solve(0, i, grid, t));
       }
       return mini;
    }
};