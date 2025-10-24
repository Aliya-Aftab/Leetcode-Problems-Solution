class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<bool>&visited){
    visited[node]=true;
    for(int i=0;i<adj[node].size();i++){
    if(!visited[adj[node][i]]){
    dfs(adj[node][i], adj, visited);
    }
    }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>>adj(n);
    for(int i=0;i<edges.size();i++){
    adj[edges[i][0]].push_back(edges[i][1]);
    adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool>visited(n,false); 
    dfs(source, adj, visited);
    if(!visited[destination]){
    return false;
    }
    return true;
    }
};