class Solution {
public:
    long long isPossible(vector<int>& candies, int candy, long long k){
    long long children=0;
    for(int i=0;i<candies.size();i++){
    children+=candies[i]/candy;
    }
    return children;
    }

    int maximumCandies(vector<int>& candies, long long k) {
    int n=candies.size();
    int maxi=INT_MIN;
    long long sum=0;
    for(int i=0;i<n;i++){
    maxi=max(maxi, candies[i]);
    sum+=candies[i];
    }
    if(k>sum){
    return 0;
    }
    int lo=1;
    int hi=maxi;
    int ans=0;
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(isPossible(candies,mid,k )>=k){
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