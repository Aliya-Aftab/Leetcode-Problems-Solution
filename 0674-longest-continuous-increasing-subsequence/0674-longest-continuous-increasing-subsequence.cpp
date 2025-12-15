class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
    int n=nums.size();
    int maxLen=1;
    int startIdx=0;
    int prevIdx=0;
    for(int i=1;i<n;i++){
    if(nums[i]>nums[prevIdx]){
    prevIdx=i;
    }
    else{
    maxLen=max(maxLen, prevIdx-startIdx+1);
    prevIdx=i;
    startIdx=i;
    }
     maxLen=max(maxLen, prevIdx-startIdx+1);
    }
    return maxLen;   
    }
};