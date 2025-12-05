class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    int m,n;

    bool isValid(int i, int j){
        return i>=0 && i<m && j>=0 && j<n;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        // 2 roles-> visited, final reachability
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        queue<pair<int,int>> q1;

        // pacific
        // first row
        for(int i=0;i<n;i++){
            q1.push({0,i});
            pacific[0][i] = 1;   
        }
        // left col
        for(int i=0;i<m;i++){
            q1.push({i,0});
            pacific[i][0] = 1;   
        }

        while(!q1.empty()){
            int i = q1.front().first;
            int j = q1.front().second;
            q1.pop();

            for(int k=0;k<4;k++){
                int ni = i + row[k];
                int nj = j + col[k];   

                if(isValid(ni, nj) && heights[ni][nj] >= heights[i][j] && !pacific[ni][nj]){
                    pacific[ni][nj] = 1;
                    q1.push({ni, nj}); 
                }
            }
        }

        queue<pair<int,int>> q2;

        // atlantic
        // last row
        for(int i=0;i<n;i++){
            q2.push({m-1,i});
            atlantic[m-1][i] = 1;    
        }
        // right col
        for(int i=0;i<m;i++){
            q2.push({i,n-1});
            atlantic[i][n-1] = 1;    
        }

        while(!q2.empty()){
            int i = q2.front().first;
            int j = q2.front().second;
            q2.pop();

            for(int k=0;k<4;k++){
                int ni = i + row[k];
                int nj = j + col[k];   

                if(isValid(ni, nj) && heights[ni][nj] >= heights[i][j] && !atlantic[ni][nj]){
                    atlantic[ni][nj] = 1;
                    q2.push({ni, nj}); 
                }
            }
        }

        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
