class Solution {
public:
    int m, n;
    bool isValid(int i, int j){
    return i>=0 && i<m && j>=0 && j<n;
    }
    int row[8]={-1,-1,-1,1,1,1,0,0};
    int col[8]={-1,0,1,-1,0,1,-1,1};
    void gameOfLife(vector<vector<int>>& board) {
    vector<vector<int>>copy=board;
     m=board.size();
    n=board[0].size();
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
    int cntOne=0;
    int cntZero=0;
    for(int k=0;k<8;k++){
    int new_i=i+row[k];
    int new_j=j+col[k];
    if(isValid(new_i,new_j )){
    if(copy[new_i][new_j]==1){
    cntOne++;
    }
    else{
    cntZero++;
    }
    }
    }
    if(copy[i][j]==1 && cntOne<2){
    board[i][j]=0;
    }
    else if(copy[i][j]==1 && (cntOne==2 || cntOne==3)){
    continue;
    }
    else if(copy[i][j]==1 && cntOne>3){
    board[i][j]=0;
    }
    if(copy[i][j]==0 && cntOne==3){
    board[i][j]=1;
    }
    }
    }
    }
};