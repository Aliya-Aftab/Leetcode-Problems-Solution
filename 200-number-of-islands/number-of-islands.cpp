class Solution {
public: 
    bool isValid(int i, int j){
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    int row[4]={-1, 1, 0, 0};
    int col[4]={0, 0, -1, 1};
    int r, c;
    int numIslands(vector<vector<char>>& grid) {
      r=grid.size();
      c=grid[0].size();
      queue<pair<int, int>>q;
      vector<vector<bool>>visited(r, vector<bool>(c, 0));
      int count=0;
      for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                count++;
                visited[i][j]=1;
                q.push({i, j});
            while(!q.empty()){
                int first=q.front().first;
                int second=q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int ro=first+row[k];
                    int co=second+col[k];
                    if(isValid(ro, co) && grid[ro][co]=='1' && visited[ro][co]==false){
                        visited[ro][co]=1;
                        q.push({ro, co});
                    }
                }
            }
            }
        }
      }
      return count;
    }
};