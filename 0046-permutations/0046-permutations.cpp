class Solution {
public:
    void generate(vector<int>&nums,int n, vector<int>&temp, vector<int>&visited, 
     vector<vector<int>>&ans){
    // base case
    if(temp.size()==nums.size()){
    ans.push_back(temp);
    return;
    }
     for(int i=0;i<n;i++){
     if(visited[i]){
     continue;
     }
     temp.push_back(nums[i]);
     visited[i]=1;
     generate(nums,n,temp,visited,ans);
     visited[i]=0;
     temp.pop_back();
     }
     }
    vector<vector<int>> permute(vector<int>& nums) {
    int n=nums.size();
    vector<int>temp;
    vector<int>visited(n,0);
    vector<vector<int>>ans;
    generate(nums,n,temp,visited,ans);
    return ans;
    }
};