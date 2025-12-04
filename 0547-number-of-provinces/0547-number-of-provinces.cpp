class Solution {
public:
   void bfs(int city, vector<vector<int>>&isConnected,   vector<bool>&visited){
    int n=isConnected.size();
    visited[city]=true;
    queue<int>q;
    q.push(city);
    while(!q.empty()){
    int temp=q.front();
    q.pop();
    for(int i=0;i<n;i++){
    if(i!=temp && isConnected[temp][i]==1 && !visited[i]){
    visited[i]=true;
    q.push(i);
    }
    }
    }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
    vector<bool>visited(n,0);
    int count=0;
    for(int i=0;i<n;i++){
    if(!visited[i]){
    bfs(i, isConnected, visited);
    count++;
    }
    } 
    return count;   
    }
};