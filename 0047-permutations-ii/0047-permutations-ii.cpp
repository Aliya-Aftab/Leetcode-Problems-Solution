class Solution {
public:
    void generate(vector<int>&nums,int n, int idx, vector<vector<int>>&ans){
     vector<int>visited(21,0);
    
    // base case
    if(idx==n){
    ans.push_back(nums);
    return;
    }

    for(int i=idx;i<n;i++){
    if(visited[nums[i]+10]==0){
     visited[nums[i]+10]=1;    
    swap(nums[idx], nums[i]);
    generate(nums, n, idx+1, ans);
    swap(nums[idx], nums[i]);
    }
    }
    }
     
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n=nums.size();
   
    vector<vector<int>>ans;
    generate(nums,n,0,ans);
    return ans;
    }
};