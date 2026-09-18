class Solution {
public:
    bool isValid(int i, int j, int n){
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    int row[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
    int col[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<vector<int>>q;
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        q.push({0, 0, 1});
        while(!q.empty()){
             vector<int>curr = q.front();
            q.pop();
            int r = curr[0];
            int c = curr[1];
            int d = curr[2];
            if(r == n-1 && c == n-1){
                return d;
            }
            for(int k = 0; k < 8; k++){
                int nr = r + row[k];
                int nc = c + col[k];
                if(isValid(nr, nc, n) && grid[nr][nc] == 0){
                    grid[nr][nc] = 1;
                    q.push({nr, nc, d+1});
                }
            }
        }
        return -1;
    }
};