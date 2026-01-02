class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
    int n=nums.size(); // 2n
    unordered_map<int,int>mp; 
    for(int i=0;i<n;i++){
    mp[nums[i]]++;
    }  
    int ans=-1;
    for(auto &it:mp){
    if(it.second==n/2){
    ans=it.first;
    }
    } 
    return ans;
    }
};