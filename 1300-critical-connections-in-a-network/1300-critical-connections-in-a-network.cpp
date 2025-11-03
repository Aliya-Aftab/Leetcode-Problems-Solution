class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>&adj,vector<int>&visited, vector<int>&low, vector<int>&disc, vector<vector<int>>&bridges, int& count){
    disc[node]=low[node]=count;
    visited[node]=1;
    for(int j=0;j<adj[node].size();j++){
    if(adj[node][j]==parent){
    continue;
    }
    else if(visited[adj[node][j]]){
    low[node]=min(low[node], low[adj[node][j]]);
    }
    else{
    count++;
    dfs(adj[node][j], node, adj, visited, low, disc, bridges, count);
    low[node]=min(low[node], low[adj[node][j]]);
    if(low[adj[node][j]]> disc[node]){
    // bridge exists
    vector<int>temp;
    temp.push_back(node);
    temp.push_back(adj[node][j]);
    bridges.push_back(temp);
    }
    }
    }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    int size=connections.size();
    vector<vector<int>>adj(n);
    for(int i=0;i<size;i++){
    int u=connections[i][0];
    int v=connections[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
    }
    vector<vector<int>>bridges;
    vector<int>disc(n);
    vector<int>low(n);
    vector<int>visited(n,0);
    int count=0;
    dfs(0, -1, adj,visited,low, disc, bridges, count);
    return bridges;
    }
};