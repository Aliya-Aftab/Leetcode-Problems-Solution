class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<roads.size();i++){
        adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});   
    }

    vector<long long> dist(n, LLONG_MAX);  
    vector<long long> ways(n, 0);  
    const long long MOD = 1e9+7;

    priority_queue< pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q; 
    // {dist, node}
    q.push({0,0});
    dist[0]=0;
    ways[0]=1;

    while(!q.empty()){
        int node=q.top().second;
        long long cost=q.top().first;
        q.pop();

        if(cost > dist[node]) continue;   

        for(int j=0;j<adj[node].size();j++){
            int neigh=adj[node][j].first;
            long long wt=adj[node][j].second;

            if(cost + wt < dist[neigh]){
                dist[neigh]=cost+wt;
                q.push({dist[neigh], neigh});
                ways[neigh]=ways[node];
            }
            else if(cost + wt == dist[neigh]){
                ways[neigh] = (ways[neigh] + ways[node]) % MOD;   
                // DO NOT update dist or push into pq here
            }
        }
    }

    return ways[n-1] % MOD;
    }
};
