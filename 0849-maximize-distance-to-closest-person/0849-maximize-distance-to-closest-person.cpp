class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
    int n=seats.size();
    int last=-1;
    int maxDist=INT_MIN;
    int dist=0;
    for(int i=0;i<n;i++){
    if(seats[i]==1){
    if(last==-1){
    dist=i;
    }
    else if(last!=-1){
    dist=(i-last)/2;
    }
    maxDist=max(maxDist, dist);
    last=i;
    }
    
    }
    maxDist=max(maxDist, (n-1)-last);
    return maxDist;
    }
};