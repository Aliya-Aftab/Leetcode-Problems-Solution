class Solution {
public: 
    bool isIncreasingSeq(vector<int>&nums,int s,int e){
    for(int i=s+1;i<e;i++){
    if(nums[i]<=nums[i-1]){
    return false;
    }
    }
    return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int n=nums.size();
    bool first;
    bool second;
    for(int i=0; i<=n-2*k; i++){
    first=isIncreasingSeq(nums,i,i+k);
    second=isIncreasingSeq(nums,i+k,i+2*k);
    if(first && second){
    return true;
    } 
    } 
    return false;  
    }
};