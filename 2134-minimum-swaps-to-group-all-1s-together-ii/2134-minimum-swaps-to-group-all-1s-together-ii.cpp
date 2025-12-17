class Solution {
public:
    int minSwaps(vector<int>& nums) {
    int n=nums.size();
    int cntOne=0;
    for(int i=0;i<n;i++){
    if(nums[i]==1){
    cntOne++;
    }
    }
    if(cntOne==0 || cntOne==n){
    return 0;
    }
    int zeros=0;
    for(int i=0;i<cntOne;i++){
    if(nums[i]==0){
    zeros++;
    }
    }
    int mini=zeros;
    for(int i=cntOne;i<2*n;i++){
    if(nums[i%n]==0){
    zeros++;
    }
    if(nums[(i-cntOne)%n]==0){
    zeros--;
    }
    mini=min(mini, zeros);
    }    
    return mini;      
    }
};