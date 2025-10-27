class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0 ;i<flights.size();i++){
    int u=flights[i][0];
    int v=flights[i][1];
    int price=flights[i][2];
    adj[u].push_back({v,price});
    } 
    vector<int>dist(n, INT_MAX); 
    queue<pair<int,int>>q;
    q.push({src,0});
    int steps=0;
    while(!q.empty() && steps<=k){
    int size=q.size();
    while(size--){
    int node=q.front().first;
    int cost=q.front().second;
    q.pop();
    for (int j = 0; j < adj[node].size(); j++) {
    int neigh = adj[node][j].first;
    int wt = adj[node][j].second;

    if (cost + wt < dist[neigh]) {
        dist[neigh] = cost + wt;
        q.push({neigh, dist[neigh]});
    }
}

    }
    steps++;
    }
    if(dist[dst]==INT_MAX){
    return -1;
    } 
    return dist[dst];  
    }
};