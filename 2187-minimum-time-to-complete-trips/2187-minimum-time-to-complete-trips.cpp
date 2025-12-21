class Solution {
public:
    bool possible(vector<int>time,long long givenTime,int totalTrips){
    int cnt=0;
    for(int i=0;i<time.size();i++){
    cnt+=givenTime/time[i];
     if(cnt>=totalTrips){
    return true;
    }
    }
    return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
    long long lo=1;
    long long hi=(long long)*min_element(time.begin(),time.end())*totalTrips;
    while(lo<=hi){
    long long mid=lo+(hi-lo)/2;
    if(possible(time,mid,totalTrips)){
    hi=mid-1;
    }
    else{
    lo=mid+1;
    }
    } 
    return lo;   
    }
};