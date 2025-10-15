class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int n=nums.size();
    int currLen=1, prevLen=0;
    for(int i=1;i<n;i++){
    if(nums[i]>nums[i-1]){
    currLen++;
    }
    else{
    prevLen=currLen;
    currLen=1;
    }
    if(currLen>=2*k){
    return true;
    }
    int mini=min(currLen, prevLen);
    if(mini>=k){
    return true;
    }    
    }  
    return false;  
    }
};