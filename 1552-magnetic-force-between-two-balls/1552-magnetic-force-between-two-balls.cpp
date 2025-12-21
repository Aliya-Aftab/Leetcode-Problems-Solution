class Solution {
public:
    bool canWePlace(vector<int> &position, int dist, int balls){
    int cntBalls=1;
    int lastPlaced=position[0];
    for(int i=1; i<position.size(); i++){
    if(position[i]-lastPlaced>=dist){
    cntBalls++;
    lastPlaced=position[i];
    }
    if(cntBalls>= balls){
    return true;
    }
    }
    return false;
    }
    int maxDistance(vector<int>& position, int m) {
    int n=position.size();
    sort(position.begin(), position.end());
    int lo=1;
    int hi=position[n-1]-position[0];
    int ans=0;
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(canWePlace(position, mid,m)){
    ans=mid;
    lo=mid+1;
    }
    else{
    hi=mid-1;
    }
    }
    return ans;
    }
};