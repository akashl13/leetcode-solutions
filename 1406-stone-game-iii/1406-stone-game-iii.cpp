class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n + 1, 0);

        // Start from the end
        for (int i = n - 1; i >= 0; i--) {
            int sum = 0;
            dp[i] = INT_MIN;

            // Take 1, 2, or 3 stones
            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += stoneValue[i + k];

                dp[i] = max(dp[i], sum - dp[i + k + 1]);
            }
        }

        if (dp[0] > 0)
            return "Alice";
        else if (dp[0] < 0)
            return "Bob";
        else
            return "Tie";
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna