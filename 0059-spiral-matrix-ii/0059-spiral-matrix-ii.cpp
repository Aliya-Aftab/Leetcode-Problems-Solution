class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>>matrix(n,vector<int>(n,0));
    int top=0,bottom=n-1,left=0,right=n-1;    
    int temp=1;
    while(top<= bottom && left<=right){
    // moving from left to right
    for(int i=left; i<=right;i++){
    matrix[top][i]=temp;
    temp++;
    }
     top++;
    // moving from top to bottom
    for(int i=top;i<=bottom;i++){
    matrix[i][right]=temp;
    temp++;
    }
    right--;
    // moving from right to left
    // IMP: check index

    if(top<=bottom){
    for(int i=right; i>=left;i--){
    matrix[bottom][i]=temp;
    temp++;
    }
    bottom--;
    }
    // moving from bottom to top
    // IMP: check index

    if(left<=right){
    for(int i=bottom;i>=top;i--){
    matrix[i][left]=temp;
    temp++;
    }
     left++;
    }
    }
    // vector<vector<int>>ans;
    // for(int i=0;i<n;i++){
    // for(int j=0;j<n;j++){
    
    // }
    // // 
    // } 
    return matrix;
    }
};