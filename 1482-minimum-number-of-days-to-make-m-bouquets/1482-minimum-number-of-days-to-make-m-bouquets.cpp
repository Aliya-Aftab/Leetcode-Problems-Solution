class Solution {
public:
    bool isPossible(vector<int>&bloomDay, int day, int m, int k){
    int cnt=0;
    int bouquets=0;
    for(int i=0;i<bloomDay.size();i++){
    if(bloomDay[i]<=day){
    cnt++;
    }
    else{
    bouquets+=cnt/k;
    cnt=0;
    }
    }
    bouquets+=cnt/k;
    return bouquets>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
    int n=bloomDay.size();
    long long check=m*1LL*k*1LL;
    if(check>n){
    return -1;
    }  
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
    maxi=max(maxi, bloomDay[i]);
    mini=min(mini, bloomDay[i]);
    }
    int res=0;
    int lo=mini;
    int hi=maxi;
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    bool ans=isPossible(bloomDay, mid, m, k);
    if(ans){
    res=mid;
    hi=mid-1;
    }
    else{
    lo=mid+1;   
    }
    }
    return res;

    }
};