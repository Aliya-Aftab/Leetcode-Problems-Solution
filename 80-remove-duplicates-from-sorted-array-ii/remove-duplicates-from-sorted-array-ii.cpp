class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return nums.size();
        }
        int i = 2, j = 2;
        while(j < n){
            if(nums[i-2] != nums[j]){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};
/*
[1,1,1,2,2,3], n = 6
i=0, j = 2  => 
i= 0,  j=3, nums[2]=3, 
i=2, j=4
i=2, j=5
*/