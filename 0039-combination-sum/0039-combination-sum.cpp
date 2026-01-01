class Solution {
public:
    void possibleCombination(vector<int>& candidates,int idx, vector<int>&temp,vector<vector<int>>&ans, int target){    
    int n=candidates.size();
    // base case
    if(target==0){
    ans.push_back(temp);
    return;
    }
    if(idx==n || target<0){
    return;
    }
    // included
    temp.push_back(candidates[idx]);
    possibleCombination(candidates,idx,temp,ans,target-candidates[idx] );
    // not included
    temp.pop_back();
     possibleCombination(candidates,idx+1,temp,ans,target );
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>temp;
    possibleCombination(candidates, 0, temp, ans, target);
    return ans;
    }
};