class Solution {
public:
    int maxi(vector<int>v){
    int n=v.size();
    int x=INT_MIN;
    for(int i=0;i<n;i++){
    x=max(x,v[i]);
    }
    return x;
    }
    long long calculateTotalHours(vector<int>v,int hours){
    long long total=0;
    for(int i=0;i<v.size();i++){
    total+=(ceil)((double)v[i]/(double)hours);
    }
    return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
    int lo=1;
    int hi=maxi(piles);
    int ans=0;
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    long long total_hrs=calculateTotalHours(piles,mid);
    if(total_hrs<=h){
    ans=mid;
    hi=mid-1;
    }
    else{
    lo=mid+1;
    }
    }
    return ans;
    }    
};