class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    int m,n;
    bool isValid(int i, int j){
    return i>=0 && i<m && j>=0 && j<n;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    m=image.size();
    n=image[0].size();
    int original=image[sr][sc];
    if(original==color){
    return image;
    }
    queue<pair<int,int>>q;
    q.push({sr,sc});
    image[sr][sc]=color;
    while(!q.empty()){
    int i=q.front().first;
    int j=q.front().second;
    q.pop();
    for(int k=0;k<4;k++){
    if(isValid(i+row[k], j+col[k]) && image[i+row[k]][j+col[k]]==original){
    image[i+row[k]][j+col[k]]=color;
    q.push({i+row[k], j+col[k]});
    }
    }
    }
    return image;
    }
};