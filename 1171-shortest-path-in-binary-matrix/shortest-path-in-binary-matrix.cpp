class Solution {
public:
    bool isValid(int i, int j, int m, int n){
    return i>=0 && i<m && j>=0 && j<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    if(grid[0][0]==1 || grid[m-1][n-1]==1){
    return -1;
    }

    int row[8]={-1,-1,-1,1,1,1,0,0};
    int col[8]={-1,0,1,-1,0,1,-1,1}; 
    queue<pair<int,int>>q;
    int count=0;
    q.push({0,0});
    grid[0][0]=1;
    while(!q.empty()){
        int size=q.size();
        count++;
        while(size--){
            int new_i=q.front().first;
            int new_j=q.front().second;
            q.pop();
            if(new_i==m-1 && new_j==n-1){
            return count;
            }
            for(int k=0; k<8; k++){
                int r=new_i+row[k];
                int c=new_j+col[k];
                if(isValid(r, c, m, n) && grid[r][c]==0){
                    grid[r][c]=1;
                    q.push({r, c});
                }
            }    
        }
    }
    if(grid[m-1][n-1]!=1){
        return -1;
    }
    return count;
    }
};