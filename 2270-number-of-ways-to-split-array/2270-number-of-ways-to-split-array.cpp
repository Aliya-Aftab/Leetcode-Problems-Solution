class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
    int n=nums.size();
    vector<long long>preSum(n,0);
    long long totalSum=0;
    for(int i=0;i<n;i++){
    totalSum+=nums[i];
    preSum[i]=totalSum;
    } 
    int count=0;
    for(int i=0;i<n-1;i++){
    long long rem=totalSum-preSum[i];
    if(preSum[i]>=rem){
    count++;
    }
    } 
    return count; 
    }
};