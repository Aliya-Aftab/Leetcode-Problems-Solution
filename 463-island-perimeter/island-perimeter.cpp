class Solution {
public:
    int m, n;
    int row[4]={-1, 1, 0, 0};
    int col[4]={0, 0, -1, 1};
    bool isValid(int i, int j){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
         int total=0;
         for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    total+=4;
                    for(int k=0; k<4; k++){
                        if(isValid(i+row[k], j+col[k]) && grid[i+row[k]][j+col[k]]==1){
                            total-=1;
                        }
                    }
                }
            }
         }
         return total;

    }
};
/*
48, 7 squares 
*/