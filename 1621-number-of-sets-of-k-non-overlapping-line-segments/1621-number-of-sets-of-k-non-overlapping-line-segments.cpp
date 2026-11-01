
class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1'000'000'007;

        vector<vector<long long>> dp(
            n, vector<long long>(k + 1, 0)
        );

        // With zero segments, there is one way:
        // choose no segments.
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i < n; i++) {
                dp[i][j] = dp[i - 1][j];

                for (int p = 0; p < i; p++) {
                    dp[i][j] =
                        (dp[i][j] + dp[p][j - 1]) % MOD;
                }
            }
        }

        return dp[n - 1][k];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna