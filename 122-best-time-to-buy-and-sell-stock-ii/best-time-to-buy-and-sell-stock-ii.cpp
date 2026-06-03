class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // Step 1: Create table of size (N+1) x 2, filled with 0s.
        // Because it's filled with 0s, the base case (dp[n][0] and dp[n][1]) is already handled!
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        // dp[index][buy] represents the absolute maximum profit you can make from day index until the end of the timeline, depending entirely on whether your hands are currently empty (buy=1) or already holding a stock (buy=0).

        // Step 2: Loop backwards from the second-to-last day down to day 0
        for (int index = n - 1; index >= 0; index--) {
            
            // Inner loop checks both states: hands full (0) and hands empty (1)
            for (int buy = 0; buy <= 1; buy++) {
                
                int profit = 0;
                
                // Step 3: Exact same logic, just looking at 'dp[index + 1]' instead of calling 'solve'
                if (buy == 1) {
                    profit = max(-prices[index] + dp[index + 1][0], 
                                  0 + dp[index + 1][1]);
                } else {
                    profit = max(prices[index] + dp[index + 1][1], 
                                  0 + dp[index + 1][0]);
                }
                
                // Store the result for the current day
                dp[index][buy] = profit;
            }
        }
        
        // At the very end, the answer for Day 0, where we are allowed to buy, is our result.
        return dp[0][1];
    }
};