class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    int n=nums.size();
    int sum=0;
    
    int maxIdx=0;
    for(int i=0;i<k;i++){
    sum+=nums[i];
    }
    double maxSum=sum; 
    for(int i=k;i<n;i++){
     sum+=nums[i];
    sum-=nums[i-k];
    if(sum>maxSum){
    maxSum=sum;
    maxIdx=i;
    }    
    }
    return (double)maxSum/k;   
    }
};