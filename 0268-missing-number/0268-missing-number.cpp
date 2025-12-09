class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int n1=nums.size();
    int xor1=0;
    int xor2=0;
    for(int i=0;i<=n1;i++){
    xor1^=i;
    }  
    for(int i=0;i<n1;i++){
    xor2^=nums[i];
    }
    return xor1^xor2;
    }
};