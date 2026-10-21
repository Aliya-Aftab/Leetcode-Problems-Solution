class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>&visited, vector<int>&path, vector<int>&safe){
        visited[node] = 1;
        path[node] = 1;
        for(int neighbour: graph[node]){
            if(!visited[neighbour]){
                if(dfs(neighbour, graph, visited, path, safe)){
                    return true;
                }
            }
            else if(path[neighbour]){
                return true;
            }
        }
        safe[node] = 1;
        path[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n, 0);
        vector<int>path(n, 0);
        vector<int>safe(n, 0);
        for(int i = 0; i < n; i++){
            dfs(i, graph, visited, path, safe);
        }
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(safe[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

/*
1. can be solved using the concept of cycle detection in an undirected 
graph as well as Kahn algorithm.
2.nodes which are part of a cycle or node which are leading to a cycle
can never be terminated into a termianl node.
*/