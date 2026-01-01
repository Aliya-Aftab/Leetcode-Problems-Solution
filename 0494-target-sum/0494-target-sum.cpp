class Solution {
public:
    int countExpressions(vector<int>&nums, int n, int idx,int currSum, int target){
    // base case
    if(idx==n){
    if(currSum==target){
    return 1;
    }
    else{
    return 0;
    }

    }
    // addition + subtraction
    return countExpressions(nums,n,idx+1,currSum+nums[idx],target) + countExpressions(nums,n,idx+1,currSum-nums[idx], target);   
    }
    int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    return countExpressions(nums,n, 0,0,target);
    }
};