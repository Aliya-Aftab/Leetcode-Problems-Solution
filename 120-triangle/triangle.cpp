class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>t=triangle[n-1];

        for(int row=n-2; row>=0; row--){
            // row 0 has 1 element, row 1 has 2 element
            // that's why iterating like col<=row.
            for(int col=0; col<=row; col++){
                t[col]=triangle[row][col]+ min(t[col], t[col+1]);
            }
        }
        return t[0];
    }
};
/*
dp[i][j] = min path sum from triangle[i][j] to bottom.
    2
   3 4
  6 5 7
 4 1 8 3  <-- Bottom Row (n-1)

    2
   3 4
  7 6 10  <-- This row now contains the "best cost to finish" from here

     2
    9 10

    11
*/