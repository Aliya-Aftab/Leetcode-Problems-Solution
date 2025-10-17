class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>adj(numCourses);
    int n=prerequisites.size();
    vector<int>inDegree(numCourses,0);
    for(int i=0;i<n;i++){
    adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    inDegree[prerequisites[i][0]]++;
    }
    // Kahn's Algorithm
    queue<int>q;
    int count=0;
    vector<int>visited(numCourses,0);
    for(int i=0;i<numCourses;i++){
    if(inDegree[i]==0){
    q.push(i);
    }
    }
    while(!q.empty()){
    int node=q.front();
    q.pop();
    count++;
    for(int j=0;j<adj[node].size();j++){
    inDegree[adj[node][j]]--;
    if(inDegree[adj[node][j]]==0){
    q.push(adj[node][j]);
    }
    }
    }
    return count==numCourses;
    }
};