class Solution {
public:
    int getMax(vector<vector<int>>& mat, int m, int n, int col){
        int maxVal = -1;
        int maxIdx = -1;
        for(int i = 0; i < m; i++){
            if(mat[i][col] > maxVal){
                maxVal = mat[i][col];
                maxIdx = i ;
            }
        }
        return maxIdx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int lo = 0;
        int hi = n-1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            int row = getMax(mat, m,n, mid);
            int left = (mid-1 >= 0) ? mat[row][mid-1]: -1;
            int right = (mid+1 < n) ? mat[row][mid+1] :-1;
            if( mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }
            else if( mat[row][mid] < left){
                hi=mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return {-1, -1};
    }
};