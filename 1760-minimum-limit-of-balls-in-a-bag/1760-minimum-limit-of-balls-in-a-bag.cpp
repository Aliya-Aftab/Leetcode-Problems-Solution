class Solution {
public:
    long long operation(vector<int>& nums, int mid){
    int n=nums.size();
    long long count=0;
    for(int i=0;i<n;i++){
    int pieces = ceil((double)nums[i] / mid);
    int ops_needed = pieces - 1;
    count += ops_needed;
    }
    return count;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
    int n=nums.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
    maxi=max(maxi, nums[i]);
    }
    int lo=1;
    int hi=maxi;   
    int ans=0;
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(operation(nums, mid)<=maxOperations){
    hi=mid-1;
    }
    else{
    lo=mid+1;
    }
    }
    return lo;
    }
};