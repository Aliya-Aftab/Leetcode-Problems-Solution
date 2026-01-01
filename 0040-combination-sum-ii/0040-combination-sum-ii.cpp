class Solution {
public:
    void possibleCombination(vector<int>& candidates,int idx, vector<int>&temp,vector<vector<int>>&ans, int target){    
    int n=candidates.size();
    // base case
    if(target==0){
    ans.push_back(temp);
    return;
    if(idx==n || target<0){
    return;
    }
    }
    
    // included
    for(int i=idx;i<n;i++){
    if(i>idx && candidates[i]==candidates[i-1]){
    continue;
    }
    if(candidates[i]>target){
    break;
    }
    temp.push_back(candidates[i]);
    possibleCombination(candidates,i+1,temp,ans,target-candidates[i] );
    // not included
    temp.pop_back();
    //  possibleCombination(candidates,idx+1,temp,ans,target );
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>temp;
    sort(candidates.begin(), candidates.end());
    possibleCombination(candidates, 0, temp, ans, target);
    return ans;    
    }
};