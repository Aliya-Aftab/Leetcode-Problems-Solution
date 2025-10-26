class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<times.size();i++){
    adj[times[i][0]].push_back({times[i][1], times[i][2]});
    }
    vector<int>dist(n+1, INT_MAX);
    vector<bool>explored(n+1);
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;    pq.push({0,k});
    dist[k]=0;
    while(!pq.empty()){
    int node=pq.top().second;
    pq.pop();
    if(explored[node]){
    continue;
    }
    explored[node]=1;
    for(int i=0;i<adj[node].size();i++){
    int neigh=adj[node][i].first;
    int wt=adj[node][i].second;
    if(!explored[neigh] && dist[node]+ wt< dist[neigh]){
    dist[neigh]=dist[node]+wt;
    pq.push({dist[neigh], neigh});
    }
    }
    }
    int maxi=0;
    for(int i=1;i<n+1;i++){
    if(dist[i]==INT_MAX){
    return -1;
    }
    maxi=max(maxi, dist[i]);
    }
    return maxi;
    }
};