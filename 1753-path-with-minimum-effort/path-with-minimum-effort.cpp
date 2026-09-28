class Solution {
public: 
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    bool isValid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({0, {0,0}});
        vector<vector<int>>dist(m, vector<int>(n, 1e9));
        dist[0][0] = 0;
        int diff = 0;
        while(!pq.empty()){
             diff = pq.top().first;
             int r = pq.top().second.first;
             int c = pq.top().second.second;
             pq.pop();
             if(r == m-1 && c == n-1){
                return diff;
             }
             for(int i = 0; i < 4; i++){
                int nr = r + row[i];
                int nc = c + col[i];
                if(isValid(nr, nc, m, n)){
                    int jumpCost = abs(heights[r][c] - heights[nr][nc]);
                    int maxDiff = max(diff, jumpCost);
                    if(dist[nr][nc] > maxDiff){
                        dist[nr][nc] = maxDiff;
                        pq.push({maxDiff, {nr, nc}});
                    }  
                }
             }
              
        }
        return dist[m-1][n-1];
    }
};