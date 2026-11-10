class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = costs[i - 1] + 1 + dp[i - 1];

            if (i >= 2) {
                dp[i] = min(dp[i],
                            dp[i - 2] + costs[i - 1] + 4);
            }

            if (i >= 3) {
                dp[i] = min(dp[i],
                            dp[i - 3] + costs[i - 1] + 9);
            }
        }

        return dp[n];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna