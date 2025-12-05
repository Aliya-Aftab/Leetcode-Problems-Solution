class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    int m,n;
    bool isValid(int i, int j){
    return i>=0 && i<m && j>=0 && j<n;
    }
    int maxDistance(vector<vector<int>>& grid) {
    m=grid.size();
     n=grid[0].size();
     queue<pair<int,int>>q;
     vector<vector<int>>dist(m, vector<int>(n,-1));
    for(int i=0; i<m;i++){
    for(int j=0;j<n;j++){
    if(grid[i][j]==1){
    q.push({i,j});
    dist[i][j]=0;
    }
    }
    } 
    // as per the question if there's all 0 or all 1's, return -1
    if(q.empty() || q.size()==m*n){
    return -1;
    }
    while(!q.empty()){
    int new_i=q.front().first;
    int new_j=q.front().second;
    q.pop();
    for(int k=0;k<4;k++){
    if(isValid(new_i+row[k], new_j+col[k]) && dist[new_i+row[k]][new_j+col[k]]==-1){
    dist[new_i+row[k]][new_j+col[k]]=dist[new_i][new_j]+1;
    q.push({new_i+row[k], new_j+col[k]});
    }
    }
    }
    int maxi=0;
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
    maxi=max(maxi, dist[i][j]);
    }
    }
    return maxi;
    }
};