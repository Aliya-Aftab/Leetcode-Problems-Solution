class Solution {
public:
    void bfs(int i, vector<vector<int>>& isConnected, vector<bool>&visited){
        queue<int>q;
        q.push(i);
        visited[i] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int j=0; j<visited.size(); j++){
                if(!visited[j] && isConnected[node][j]==1){
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n, 0);
        int province = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                province++;
                bfs(i, isConnected, visited);
            }
        }
        return province;
    }
};