class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int>q;
        vector<int>colour(n, -1);
        for(int i=0; i<n; i++){
            if(colour[i]==-1){
                colour[i]=0;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int x: graph[node]){
                        if(colour[x]==-1){
                            colour[x]=(colour[node]+1)%2;
                            q.push(x);
                        }
                        else{
                            if(colour[node]==colour[x]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};