class Solution {
public:
    int m, n;
vector<vector<int>> dp;
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i == m || j == n) {
            return -1e9;
        }
        if (dp[i][j] != -2e9) {
            return dp[i][j];
        }
        int op1 = solve(nums1, nums2, i, j + 1);
        int op2 = solve(nums1, nums2, i + 1, j);
        int op3 = nums1[i] * nums2[j] + max(0, solve(nums1, nums2, i + 1, j + 1));
        return dp[i][j] = max(op1, max(op2, op3));
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        dp.assign(m, vector<int>(n, -2e9));
        return solve(nums1, nums2, 0, 0);
    }
};
