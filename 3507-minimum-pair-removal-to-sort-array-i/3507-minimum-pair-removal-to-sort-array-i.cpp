class Solution {
public:
    int minSum(vector<int>&nums){
    int maxi=INT_MAX;
    int idx=-1;
    for(int i=0;i<nums.size()-1;i++){
    if(nums[i]+nums[i+1]<maxi){
    maxi=nums[i]+nums[i+1];
    idx=i;
    }
    }
    return idx;
    }
    int minimumPairRemoval(vector<int>& nums) {
    int n=nums.size();
     int ans=0;
    while(!is_sorted(nums.begin(), nums.end())){
    int idx=minSum(nums);
    nums[idx]=nums[idx]+nums[idx+1];
    nums.erase(nums.begin()+idx+1);
    ans++;
    }
    return ans;
    }
};