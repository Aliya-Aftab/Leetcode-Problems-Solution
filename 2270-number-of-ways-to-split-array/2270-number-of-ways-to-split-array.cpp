class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
    int n=nums.size();
    // vector<long long>preSum(n,0);
    long long totalSum=0;
    for(int i=0;i<n;i++){
    totalSum+=nums[i];
    } 
    int count=0;
    long long leftSum=0;
    for(int i=0;i<n-1;i++){
    leftSum+=nums[i];
    long long rightSum=totalSum-leftSum;
    if(leftSum>=rightSum){
    count++;
    }
    } 
    return count; 
    }
};