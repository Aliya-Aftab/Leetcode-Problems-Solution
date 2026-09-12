class Solution {
public: 
    bool solve(int node, vector<vector<int>>& graph, vector<int>& color){
        for(int x: graph[node]){
            if(color[x] == -1){
                color[x] = !color[node];
                if(!solve(x, graph, color)){
                    return false;
                }
            }
            else{
                if(color[x] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!solve(i, graph, color)){
                    return false;
                }
            }
        }
        return true;
    }
};