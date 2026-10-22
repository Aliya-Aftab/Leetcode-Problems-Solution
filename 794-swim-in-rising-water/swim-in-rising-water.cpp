class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        vector<vector<int>>dist(n, vector<int>(n, 1e9));
        pq.push({grid[0][0], {0, 0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int maxDist = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r == n-1 && c == n-1){
                return maxDist;
            }
            for(int k = 0; k < 4; k++){
                int nr = r + row[k];
                int nc = c + col[k];
                if(isValid(nr, nc, n, n) && dist[nr][nc] > max(maxDist, grid[nr][nc])){
                    dist[nr][nc] = max(maxDist, grid[nr][nc]);
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
        return 0;
    }
};

/*
grid[i][j] = elevation at point i, j.
time t = water level t. level <= t => reachable
curr cell + future cell <= t => only then we can swim
return min time to reach cell n-1, n-1


*/