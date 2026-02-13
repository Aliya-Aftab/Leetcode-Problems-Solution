class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    int n=asteroids.size();
    vector<int>ans;
    bool flag=true;
    for(int i=0;i<n;i++){
    flag=true;
    while(!ans.empty() && ans.back()>0 && asteroids[i]<0 ){
    if(ans.back()<abs(asteroids[i])){
    ans.pop_back();
    }
    else if(ans.back()==abs(asteroids[i])){
    ans.pop_back();
    flag=false;
    break;
    }
    else{
    flag=false;
    break;
    }
    }
    if(flag)
    ans.push_back(asteroids[i]);
    }  
    return ans; 
    }
};