class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
    int n=nums.size();
    sort(nums.begin(), nums.end());
    int smallest=nums[0]+k;
    int largest=nums[n-1]-k;
    int ans=nums[n-1]-nums[0];
    for(int i=0;i<n-1;i++){
    // if (nums[i+1] - k < 0) {
    // continue;
    // }
    int mini=min(smallest, nums[i+1]-k);
    int maxi=max(largest, nums[i]+k);
    ans=min(ans, maxi-mini);
    } 
    return ans; 
    }
};

// TC : O(nlogn)
// SC : O(1)