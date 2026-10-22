class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create adjacency list
        vector<vector<pair<int, int>>>adj(n+1);
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];
            adj[u].push_back({v, time});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>dist(n+1, 1e9);
        pq.push({k, 0});
        dist[k] = 0;
        while(!pq.empty()){
            int node = pq.top().first;
            int t = pq.top().second;
            pq.pop();
            for(auto &it: adj[node]){
                int adjNode = it.first;
                int timeToAdj = it.second;
                if(dist[adjNode] > t + timeToAdj){
                    dist[adjNode] = t + timeToAdj;
                    pq.push({adjNode, dist[adjNode]});
                }
            }
        }
        int maxi = 0;
        for(int i = 1; i < n+1; i++){
            if(dist[i] == 1e9){
                return -1;
            }
            maxi = max(maxi, dist[i]);
        }
        return maxi;
        //

    }
};