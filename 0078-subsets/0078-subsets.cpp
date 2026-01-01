class Solution {
public:
    void Generate(vector<int>&nums, int n, int idx, vector<int>&temp,
    vector<vector<int>>&ans){
    // base case
    if(idx==n){
    ans.push_back(temp);
    return;
    }
    // not include
    Generate(nums, n, idx+1, temp, ans);
    // include
    temp.push_back(nums[idx]);
    Generate(nums, n, idx+1, temp, ans);
    temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<int>temp;
    vector<vector<int>>ans;
    int idx=0;
    int n=nums.size();    
    Generate(nums, n, idx, temp, ans);
    return ans;
    }
};