class Solution {
public:
    bool isValid(int i, int j, int m, int n){
    return i>=0 && i<m && j>=0 && j<n;
    }
    void solve(vector<vector<char>>& board) {
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    int m=board.size();
    int n=board[0].size();
    queue<pair<int,int>>q;
    // first row
    for(int i=0;i<n;i++){
    if(board[0][i]=='O'){
    q.push({0,i});
    board[0][i]='T';
    }
    }
    // first col
    for(int i=1;i<m;i++){
    if(board[i][0]=='O'){
    q.push({i,0});
    board[i][0]='T';
    }
    }
    // last row
    for(int i=1;i<n;i++){
    if(board[m-1][i]=='O'){
    q.push({m-1,i});
    board[m-1][i]='T';
    }
    } 
    // last col
    for(int i=1;i<m;i++){
    if(board[i][n-1]=='O'){
    q.push({i,n-1});
    board[i][n-1]='T';
    }
    }
    while(!q.empty()){
     int new_i = q.front().first;
    int new_j = q.front().second;
    q.pop();
    for(int k=0;k<4;k++){
    if(isValid(new_i+row[k],new_j+col[k],m,n) && board[new_i+row[k]][new_j+col[k]]=='O'){
    q.push({new_i+row[k],new_j+col[k]});
    board[new_i+row[k]][new_j+col[k]]='T';
    }
    }
    } 
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
    if(board[i][j]=='O'){
    board[i][j]='X';
    }
    if(board[i][j]=='T'){
    board[i][j]='O';
    }
    }
    } 
    }
};