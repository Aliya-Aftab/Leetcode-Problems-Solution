class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int i=0,j=0;
    int n=nums.size();
    int cntZeros=0;
    int maxi=INT_MIN;
    while(j<n){
    if(nums[j]==0){
    cntZeros++;
    }
    while(cntZeros>k){
    if(nums[i]==0){
    cntZeros--;
    }
    i++;
    }
    maxi=max(maxi, j-i+1);
    j++;
    }
    return maxi;    
    }
};