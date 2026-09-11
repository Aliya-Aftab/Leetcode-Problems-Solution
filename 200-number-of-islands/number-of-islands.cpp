class Solution {
public:
    int m, n;
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    bool isValid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void bfs(int i, int j,  vector<vector<int>>&visited,  vector<vector<char>>&grid){
        queue<pair<int, int>>q;
        q.push({i, j});
        visited[i][j] = 1;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++){
            int newr = r + row[k];
            int newc = c + col[k];
            if(isValid(newr, newc, m, n) && !visited[newr][newc] && grid[newr][newc] == '1'){
                visited[newr][newc] = 1;
                q.push({newr, newc});
            }
            }
        }    
    }

    int numIslands(vector<vector<char>>& grid) {
         m = grid.size();
         n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n, 0));
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i, j, visited, grid);
                }
            }
        }
        return count;
    }
};