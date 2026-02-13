class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int>ans(k, INT_MAX);
    vector<int>temp;
    for(int i=0;i<n;i++){
    while(!temp.empty() && temp.back()>nums[i] && temp.size()-1+(n-i)>=k){
    temp.pop_back();
    }
    temp.push_back(nums[i]);
     if(temp.size()==k){
    ans=min(ans,temp);
    }
    } 
    if(temp.size()==k){
    ans=min(ans,temp);
    }
    return ans;   
    }
};