class Solution {
public:
    int atmostkOdd(vector<int>& nums, int k){
    int n=nums.size();
    int l=0,r=0;
    int cntOdd=0;
    int cntSubarrays=0;
    while(r<n){
    if(nums[r]%2==1){
    cntOdd++;
    }
    while(cntOdd>k){
    if(nums[l]%2==1){
    cntOdd--;
    }
    l++;
    }
    cntSubarrays+=r-l+1;
    r++;
    }
    return cntSubarrays;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
    return atmostkOdd(nums,k)-atmostkOdd(nums,k-1);
    }
};