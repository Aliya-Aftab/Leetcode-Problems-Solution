class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
    int n=nums.size();
    int ans=0;
    int evenSum=0;
    int oddSum=0;
    for(int i=0; i<n; i++){
    if(i%2==0){
    evenSum+=nums[i];
    }
    else{
    oddSum+=nums[i];
    }
    } 
    int evenLeft=0, oddLeft=0;  
    int evenRight=0, oddRight=0;  
    for(int i=0;i<n;i++){
    if(i%2==0){
    evenRight=evenSum-(evenLeft+nums[i]);
    oddRight=oddSum-oddLeft;
    }
    else{
    evenRight=evenSum-evenLeft;
    oddRight=oddSum-(oddLeft + nums[i]);
    }
    if(evenLeft+oddRight==oddLeft + evenRight){
    ans++;
    }


    if(i%2==0){
    evenLeft+=nums[i];
    }
    else{
    oddLeft+=nums[i];
    }
    }
    return ans;
    }
};