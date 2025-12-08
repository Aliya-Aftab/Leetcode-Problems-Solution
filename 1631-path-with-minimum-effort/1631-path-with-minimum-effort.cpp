class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    int m,n;

    bool isValid(int i, int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    typedef pair<int, pair<int,int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
      m=heights.size();
     n=heights[0].size();
vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    priority_queue<P, vector<P>, greater<P>>pq;
    pq.push({0,{0,0}});
    dist[0][0]=0;
    while(!pq.empty()){
    int diff=pq.top().first;
    int i=pq.top().second.first;
    int j=pq.top().second.second;
    pq.pop();
    if(i==m-1 && j==n-1){
    return diff;
    }
    for(int k=0;k<4;k++){
    int new_i=i+row[k];
    int new_j=j+col[k];
    if(isValid(new_i, new_j) ){
    int absDiff=abs(heights[new_i][new_j]- heights[i][j]);
    int maxDiff= max(diff, absDiff);
    if(dist[new_i][new_j] > maxDiff){
    dist[new_i][new_j]=maxDiff;
    pq.push({maxDiff,{new_i, new_j}});
    }
    }
    }
    }
    return dist[m-1][n-1];
    }
};