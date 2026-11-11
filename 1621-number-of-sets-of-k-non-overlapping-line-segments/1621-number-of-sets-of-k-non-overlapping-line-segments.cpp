class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1000000007LL;

        // dp[i][j] = number of ways to draw j segments
        // using points 0 ... i.
        vector<vector<long long>> dp(
            n, vector<long long>(k + 1, 0)
        );

        // With 0 segments, there is exactly 1 way
        // for any number of points: draw nothing.
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= k; j++) {
            long long prefix = 0;

            for (int i = 1; i < n; i++) {

                // dp[i-1][j] = don't use point i
                dp[i][j] = dp[i - 1][j];

                // Choose the starting point of the last segment.
                // prefix contains:
                // dp[0][j-1] + ... + dp[i-1][j-1]
                prefix = (prefix + dp[i - 1][j - 1]) % MOD;

                dp[i][j] = (dp[i][j] + prefix) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna