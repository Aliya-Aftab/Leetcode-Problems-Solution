class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
    int n=nums.size();
    int cnt=0;
    if(k<0){
    return 0;
    } 
    unordered_map<int,int>mp;
    for(int num: nums){
    mp[num]++;
    }
    if(k==0){
    for(auto it:mp){
    if(it.second>=2){
    cnt++;
    }
    }
    }
    if(k>0){
    for(auto it: mp){
    int x=it.first;
    if(mp.find(x+k)!=mp.end()){
    cnt++;
    }
    }
    }
    return cnt;   
    }
};