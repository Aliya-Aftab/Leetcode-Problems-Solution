class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
    int n=nums.size();
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
    mini=min(mini,nums[i]);
    maxi=max(maxi, nums[i]);
    }
    if((maxi-k)-(mini+k)<0){
    return 0;
    }
    return (maxi-k)-(mini+k);    
    }
};