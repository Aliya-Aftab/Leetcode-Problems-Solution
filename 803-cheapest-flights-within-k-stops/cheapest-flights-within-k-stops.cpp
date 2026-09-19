class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>adj[n];
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];
            adj[u].push_back({v, price});
        }
        int stop = 0;
        queue<pair<int, pair<int, int>>>q;
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
        q.push({stop, {src, 0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stop > k){
                continue;
            }
            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(cost + wt < dist[adjNode] && stop <= k){
                    dist[adjNode] = cost + wt;
                    q.push({stop+1, {adjNode, cost + wt}});
                }
            }
        }
        if(dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};

/*
only storing distance in the priority queue, will not work fine here
because using the concept of the djikstra, it will fail to compute the correct 
result because we can have, least cost possible but the stoppage will be more than required
in a queue, need to store the {stops, {node, dist}}
*/