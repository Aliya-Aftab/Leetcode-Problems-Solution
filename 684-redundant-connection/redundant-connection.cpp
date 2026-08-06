class Solution {
public:
    bool canReach(int src, int dest, vector<int>&visited, vector<vector<int>>&adj){
        if(src == dest){
            return true;
        }
        visited[src]=1;
        for(int x: adj[src]){
            if(!visited[x]){
                if(canReach(x, dest, visited, adj)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for(int i=0; i<n; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            vector<int>visited(n+1, 0);
            if(canReach(u, v, visited, adj)){
                return{u,v};
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};