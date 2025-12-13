class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    int row=0;
    int col=0;
    // if any zero present in first row, set row=1
    for(int j=0;j<n;j++){
    if(matrix[0][j]==0){
    row=1;
    break;
    }
    }
    // if any zero present in first col, set col=1
    for(int i=0;i<m;i++){
    if(matrix[i][0]==0){
    col=1;
    break;
    }
    }
    // traverse the matrix from first row and first col, ans mark corresponding zeros position in
    // first row and first col
    for(int i=1;i<m;i++){
    for(int j=1;j<n;j++){
    if(matrix[i][j]==0){
    matrix[i][0]=0;
    matrix[0][j]=0;
    }
    }
    }
    // traverse the entire array and now set the rows and cols if there is
    // set values of zero 
    for(int i=1;i<m;i++){
    for(int j=1;j<n;j++){
    if(matrix[i][0]==0 || matrix[0][j]==0){
    matrix[i][j]=0;
    }
    }
    }
    // update the first row
    if(row){
    for(int j=0;j<n;j++){
    matrix[0][j]=0;
    }
    }
    // update the first col
    if(col){
    for(int i=0;i<m;i++){
    matrix[i][0]=0;
    }
    }

    }
};