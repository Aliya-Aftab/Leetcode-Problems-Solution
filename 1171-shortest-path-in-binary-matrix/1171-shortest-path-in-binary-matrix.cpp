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
    int i=q.front().first;
    int j=q.front().second;
    if (i == m - 1 && j == n - 1)
    return count;
    q.pop();
    for(int k=0;k<8;k++){
    if(isValid(i+row[k],j+col[k],m,n) && grid[i+row[k]][j+col[k]]==0){
    q.push({i+row[k],j+col[k]});
    grid[i+row[k]][j+col[k]]=1;
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