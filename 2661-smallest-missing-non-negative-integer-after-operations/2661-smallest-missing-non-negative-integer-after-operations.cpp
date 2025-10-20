class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
    int n=nums.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
    int mod_value=((nums[i]%value)+value)%value;
    mp[mod_value]++;
    }
    int ans=0;
    while((mp[ans%value]) > 0){
    mp[ans%value]--;
    ans++;
    } 
    return ans;   
    }
};