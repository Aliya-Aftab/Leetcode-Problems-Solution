class Solution {
public:
    bool detectCycle(int node, vector<vector<int>>&graph, vector<int>&path, vector<int>&visited, vector<int>&safe){
    visited[node]=true;
    path[node]=true;
    for(int i=0;i<graph[node].size();i++){
    if(path[graph[node][i]]){
    return true;
    }
    if(visited[graph[node][i]]){
    continue;
    }
    if(detectCycle(graph[node][i],graph, path, visited, safe)){
    return true;
    }
    }
    path[node]=false;
    safe[node] = true; 
    return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int>ans;
    int n=graph.size();
    vector<int>path(n,0);
    vector<int>visited(n,0);
    vector<int> safe(n, 0);

    for(int i=0;i<n;i++){
    if(!visited[i]){
    detectCycle(i, graph, path, visited, safe);
    }
    }
    for(int i=0;i<n;i++){
    if(safe[i]){
    ans.push_back(i);
    }
    }
    return ans;
    }
};