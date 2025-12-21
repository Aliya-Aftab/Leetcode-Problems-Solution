class Solution {
public:
    bool distribution(vector<int>&quantities,int cap, int n){
    long long stores=0;
    for(int i=0;i<quantities.size();i++){
    stores+=ceil((double)quantities[i]/(double)cap);
    }
    return stores<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
    int size=quantities.size();
    
    int maxi=INT_MIN;
    for(int i=0;i<size;i++){
    maxi=max(maxi, quantities[i]);
    }
    int lo=1;
    int hi=maxi;
    int ans=0;
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(distribution(quantities, mid, n)){
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