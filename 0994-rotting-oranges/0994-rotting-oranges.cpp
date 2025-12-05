
class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    bool isValid(int i, int j, int m, int n){
    return i>=0 && i<m && j>=0 && j<n;
    }

    int orangesRotting(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    queue<pair<int,int>>q;
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
    if(grid[i][j]==2){
    q.push({i,j});
    }
    }
    } 
    int minutes=0;
    while(!q.empty()){
    minutes++;
    int rottenOrange=q.size();
    while(rottenOrange--){
    int i=q.front().first;
    int j=q.front().second;
    q.pop();
    for(int k=0;k<4;k++){
    if(isValid(i+row[k],j+col[k],m,n) && grid[i+row[k]][j+col[k]]==1 ){
    grid[i+row[k]][j+col[k]]=2;
    q.push({i+row[k],j+col[k]});
    }
    }
    }
    }
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
    if(grid[i][j]==1){
    return -1;
    }
    }
    }
    if(minutes==0){
    return 0;
    }
    return minutes-1;
    }
};