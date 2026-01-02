class Solution {
public:
    void generate(vector<int>&nums,int n, vector<vector<int>>&ans, int idx){
    // base case
    if(idx==n){
    ans.push_back(nums);
    return;
    }
    for(int i=idx;i<n;i++){
    swap(nums[idx], nums[i]);
    generate(nums,n,ans,idx+1);
    swap(nums[idx], nums[i]);
    }
    }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>ans;
    int n=nums.size() ;
    generate(nums,n,ans,0);
    return ans;
    }
};