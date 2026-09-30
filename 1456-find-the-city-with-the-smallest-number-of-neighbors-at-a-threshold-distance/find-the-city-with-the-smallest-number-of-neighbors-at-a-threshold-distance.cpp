class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
        int sz = edges.size();
        for(int i = 0; i < sz; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int i = 0; i < n; i++){
            dist[i][i] = 0;
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX ){
                        continue;
                    }
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int countCity = n;
        int cityNo = -1;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= countCity){
                countCity = count;
                cityNo = i;
            }
        }
        return cityNo;
    }
};
/*
1. Make the floyd warshall algorithm matrix so that from each single city to every other city, we can compute the shortest distance.
2. Count the number of city < distanceThreshold and keep updating if 
we get min number.

*/