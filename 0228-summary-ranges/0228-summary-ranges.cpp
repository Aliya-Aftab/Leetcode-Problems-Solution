class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    int n=nums.size();
    vector<string>ans;
    if(n == 0) return ans;
    int prev=nums[0];
    int start=nums[0];
    for(int i=1;i<n;i++){
    if(prev+1==nums[i]){
    prev=nums[i];
    }
    else{
    if(start!=prev){    
    string temp=to_string(start)+"->"+ to_string(prev);
    
    ans.push_back(temp);
    
    }
    else{
    ans.push_back(to_string(start));
    }
    start=nums[i];
    prev=nums[i];
    }
    } 
    if(start!=prev){    
    string temp=to_string(start)+"->"+ to_string(prev);
    
    ans.push_back(temp);
    
    }
    else{
    ans.push_back(to_string(start));
    }
    return ans;   
    }
};