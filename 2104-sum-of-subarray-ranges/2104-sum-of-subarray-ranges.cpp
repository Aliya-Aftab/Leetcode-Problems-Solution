class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
    int n=nums.size();
    long long mini=0;
    long long maxi=0;
    long long sum=0;
    for(int i=0;i<n;i++){
    mini=nums[i];
    maxi=nums[i];
    for(int j=i;j<n;j++){
    mini=min(mini,(long long) nums[j]);
    maxi=max(maxi, (long long)nums[j]);
    sum+=maxi-mini;
    }
    }
    return sum;    
    }
};