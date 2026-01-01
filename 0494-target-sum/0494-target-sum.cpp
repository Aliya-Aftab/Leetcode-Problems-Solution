class Solution {
public:
    int countExpressions(vector<int>&nums, int n, int idx,int &currSum, int target){
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
    currSum+=nums[idx];
    int add=countExpressions(nums,n,idx+1,currSum,target);
    currSum-=nums[idx];
    
    currSum-=nums[idx];
    int sub=countExpressions(nums,n,idx+1,currSum, target);  
    currSum += nums[idx];
    return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    int currSum=0;
    return countExpressions(nums,n, 0,currSum,target);
    }
};