class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
    int n=nums.size();
    int currLen=1, prevLen=0;
    int mini=0;
    for(int i=1;i<n;i++){
    if(nums[i]>nums[i-1]){
    currLen++;
    }
    else{
    prevLen=currLen;
    currLen=1;
    }
    mini=max(mini,currLen/2);
    mini=max(mini, min(currLen, prevLen));
    }
    return mini;      
    }
};