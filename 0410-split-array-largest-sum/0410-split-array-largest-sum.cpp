class Solution {
public:
    int cntSubarrays(vector<int>& nums, int maxSum){
    int cnt=1;
    int sum=nums[0];
    for(int i=1;i<nums.size(); i++){
    if(nums[i]+sum<=maxSum){
    sum+=nums[i];
    }
    else{
    sum=nums[i];
    cnt++;
    }
    }
    return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
    int n=nums.size();
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
    maxi=max(maxi, nums[i]);
    sum+=nums[i];
    }
    int lo=maxi;
    int hi=sum;
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(cntSubarrays(nums,mid)>k){
    lo=mid+1;
    }
    else{
     hi=mid-1;
    }
    } 
    return lo;  
    }
};