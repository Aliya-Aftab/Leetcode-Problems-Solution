class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    unordered_map<int, int>mp;
    for(int i=1;i<=n;i++){
    mp[i]=0;
    }
    
    for(int i=0;i<trust.size();i++){
    mp[trust[i][1]]++;
    }
    for(auto &it: mp){
    if(it.second==n-1){
    bool flag=true;
    for(int i=0;i<trust.size();i++){
    if(it.first==trust[i][0]){
    flag=false;
    break;
    }
    }
    if(flag){
    return it.first;
    }
    }
    }
    return -1;     
    }
};