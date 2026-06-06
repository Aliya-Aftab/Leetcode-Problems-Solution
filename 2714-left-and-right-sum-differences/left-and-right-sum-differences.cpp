class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 0);
        int leftSum=0;
        int totalSum=0;
        for(int i=0; i<n; i++){
            ans[i]=leftSum;
            leftSum+=nums[i];
            totalSum+=nums[i];
        }
        int currSum=0;
        for(int i=0; i<n; i++){
            currSum+=nums[i];
            int rightSum=totalSum-currSum;
            ans[i]=abs(ans[i]-rightSum);
            
        }
        return ans; 
    }
};
/*

*/