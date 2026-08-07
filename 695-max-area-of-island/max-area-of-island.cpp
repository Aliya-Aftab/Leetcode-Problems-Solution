class Solution {
public:
    int row[4]={-1, 1, 0, 0};
    int col[4]={0, 0, -1, 1};
    bool isValid(int i, int j, int m, int n){
        return i>=0 && i<m && j>=0 && j<n;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>>q;
        int currArea=0;
        int maxArea=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                currArea = 0;
                if(grid[i][j]==1){
                    q.push({i, j});
                    grid[i][j]=0;
                    while(!q.empty()){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        currArea++;
                        for(int k=0; k<4; k++){
                            int newRow=r+row[k];
                            int newCol=c+col[k];
                            if(isValid(newRow, newCol, m, n) && grid[newRow][newCol]==1){
                                q.push({newRow, newCol});
                                grid[newRow][newCol]=0;
                            }
                        }
                    }
                    maxArea=max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};