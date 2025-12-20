class Solution {
public:
    int findDays(vector<int>&weights,int cap){
    int d=1;
    int load=0;
    for(int i=0;i<weights.size(); i++){
    if(weights[i]+load<=cap){
    load+=weights[i];
    }
    else{
    d++;
    load=weights[i];
    }
    }
    return d;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<weights.size();i++){
    maxi=max(maxi,weights[i]);
    sum+=weights[i];
    }
    int lo=maxi;
    int hi=sum;
    int ans=-1;
    while(lo<=hi){
    int mid=hi+(lo-hi)/2;
    int calcDays=findDays(weights,mid);
    if(calcDays<=days){
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