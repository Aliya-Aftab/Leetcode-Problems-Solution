class Solution {
public:
    
    void possibleCombination(vector<int>& candidates,int idx, vector<int>&temp,vector<vector<int>>&ans, int target, int k){    
    int n=candidates.size();
    // base case
    if(target==0 && temp.size()==k){
    ans.push_back(temp);
    return;
    }
    if(idx==n || target<0){
    return;
    }
    // included
    temp.push_back(candidates[idx]);
    possibleCombination(candidates,idx+1,temp,ans,target-candidates[idx],k );
    // not included
    temp.pop_back();
     possibleCombination(candidates,idx+1,temp,ans,target,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
    vector<int>candidates={1,2,3,4,5,6,7,8,9};
    vector<vector<int>>ans;
    vector<int>temp;
    possibleCombination(candidates, 0, temp, ans, n,k);
    return ans;   
    }
};