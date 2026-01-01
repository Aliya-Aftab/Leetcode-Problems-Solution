class Solution {
public:

    int memo[201][10001]; 

    bool canFind(vector<int>& nums, int n, int idx, int target) {
        // Base Cases
        if (target == 0) return true;
        if (idx == n || target < 0) return false;

        // STEP 1: Check if we already solved this state
        if (memo[idx][target] != -1) {
            return memo[idx][target];
        }

        // STEP 2: Store the result before returning
        bool result = canFind(nums, n, idx + 1, target - nums[idx]) || 
                      canFind(nums, n, idx + 1, target);
        
        return memo[idx][target] = result;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i : nums) sum += i;

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        // Initialize memo table with -1
        memset(memo, -1, sizeof(memo));

        return canFind(nums, n, 0, target);
    }
};