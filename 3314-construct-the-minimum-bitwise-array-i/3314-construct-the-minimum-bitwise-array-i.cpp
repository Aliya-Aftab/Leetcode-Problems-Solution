class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int n : nums) {
            // If n is 2, cannot construct
            if (n == 2) {
                ans.push_back(-1);
            } else {
                // Find the minimal x such that x | (x+1) = n
                int x = 0;
                for (int i = 0; i < n; i++) {
                    if ((i | (i + 1)) == n) {
                        x = i;
                        break;
                    }
                }
                ans.push_back(x);
            }
        }
        return ans;
    }
};
