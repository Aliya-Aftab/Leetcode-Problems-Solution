class Solution {
public: 
    void dfs(int node, vector<vector<int>>&adj, vector<bool>&visited ){
    visited[node]=1;
    for(int i=0;i<adj[node].size();i++){
    if(!visited[adj[node][i]]){
    dfs(adj[node][i], adj, visited);
    }
    }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
    int total_cables=connections.size();
    if(total_cables < n-1){
    return -1;
    }
    vector<vector<int>>adj(n);
    for(int i=0;i<connections.size(); i++){
    adj[connections[i][0]].push_back(connections[i][1]);
    adj[connections[i][1]].push_back(connections[i][0]);
    }
    vector<bool>visited(n,0);
     int count=0;
    for(int i=0;i<n;i++){
    if(!visited[i]){
    count++;
     dfs(i, adj, visited);
    }
    }
   
   
    // for(int i=0;i<n;i++){
    // if(!visited[i]){
    // count++;
    // }
    // }
    return count-1;
    }
};