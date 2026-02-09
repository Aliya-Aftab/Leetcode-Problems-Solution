class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

    vector<int>temp(n,0);
    for(int i=0;i<trust.size();i++){
    temp[trust[i][0]-1]--;
    temp[trust[i][1]-1]++;
    } 
    for(int i=0;i<n;i++){
    if(temp[i]==n-1){
    return i+1;
    }
    }
    return -1;
    }
};