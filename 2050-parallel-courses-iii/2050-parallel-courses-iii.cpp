class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    // create adjacency list
    vector<vector<int>>adj(n);
    vector<int>inDegree(n,0);
    for(int i=0;i<relations.size();i++){
    adj[relations[i][0]-1].push_back(relations[i][1]-1);
    inDegree[relations[i][1]-1]++;
    }
    vector<int>courseTime(n,0);
    queue<int>q;
    // Kahn;s Algorithm
    for(int i=0;i<n;i++){
    if(!inDegree[i]){
    q.push(i);
    }
    }
    while(!q.empty()){
    int node=q.front();
    q.pop();
    for(int j=0;j<adj[node].size();j++){
    inDegree[adj[node][j]]--;
    if(!inDegree[adj[node][j]]){
    q.push(adj[node][j]);
    }
    courseTime[adj[node][j]]=max(courseTime[adj[node][j]], courseTime[node]+time[node]);
    }
    }
    int ans=0;
    for(int i=0;i<n;i++){
    ans=max(ans, courseTime[i]+time[i]);
    }
    return ans;
    }
};