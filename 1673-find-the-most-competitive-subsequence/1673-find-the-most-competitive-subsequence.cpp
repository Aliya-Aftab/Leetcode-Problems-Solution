class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int>temp;
    for(int i=0;i<n;i++){
    while(!temp.empty() && temp.back()>nums[i] && temp.size()-1+(n-i)>=k){
    temp.pop_back();
    }
    if(temp.size()<k)
    temp.push_back(nums[i]);
    } 
    return temp;   
    }
};