class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n=nums.size();
    if(k<=1){
    return 0;
    }
    int left=0, right=0;
    int prod=1;
    int count=0;
    while(right<n ){
    prod*=nums[right];
    while(prod>=k){
    prod=prod/nums[left];
    left++;
    }
    count+=right-left+1;
    right++;
    } 
    return count;    
    }
};