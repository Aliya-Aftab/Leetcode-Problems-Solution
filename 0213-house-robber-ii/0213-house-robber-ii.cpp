class Solution {
public:
    int robbery(vector<int>& nums) {
    int n=nums.size();
    if(n==0){
    return 0;
    }   
    if(n==1){
    return nums[0];
    } 
    int prev2=nums[0];
    int prev1=max(nums[0], nums[1]);
    for(int i=2;i<n;i++){
    int pick=nums[i]+prev2;
    int notPick=0+prev1;
    int curr=max(pick, notPick);
    prev2=prev1;
    prev1=curr;
    }
    return prev1;
    }
    int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==0){
    return 0;
    }   
    if(n==1){
    return nums[0];
    } 
    vector<int>arr1(n-1);
    vector<int>arr2(n-1);
    for(int i=0;i<n-1;i++){
    arr1[i]=nums[i];
    }
    for(int i=1;i<n;i++){
    arr2[i-1]=nums[i];
    }
    int ans1=robbery(arr1);
    int ans2=robbery(arr2);
    return max(ans1, ans2);
    }
};