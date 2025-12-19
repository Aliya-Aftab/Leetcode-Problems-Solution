class Solution {
public:
    int findMin(vector<int>& nums) {
    int n=nums.size();
    int ans=INT_MAX;
    // int lo=0, hi=n-1;
    // int ans=INT_MAX;
    // while(lo<=hi){
    // int mid=lo+(hi-lo)/2;

    // }    
    for(int i=0;i<n;i++){
    ans=min(ans,nums[i]);
    }
    return ans;
    }
};