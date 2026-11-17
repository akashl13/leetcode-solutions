class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        // cost[l][r] = minimum changes to make s[l..r]
        // a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        // Precompute cost for every substring
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {

                int len = r - l + 1;

                // Try every valid divisor d of length
                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    // For each group
                    for (int start = 0; start < d; start++) {

                        int i = l + start;
                        int j = l + start + len - d;

                        // Make this group a palindrome
                        while (i < j) {
                            if (s[i] != s[j])
                                changes++;

                            i += d;
                            j -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // dp[i][p] = minimum changes to split
        // first i characters into p parts
        vector<vector<int>> dp(
            n + 1,
            vector<int>(k + 1, 1e9)
        );

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {

            for (int i = 1; i <= n; i++) {

                // Last part starts at j
                for (int j = 0; j < i; j++) {

                    // We need at least one character
                    if (dp[j][parts - 1] == 1e9)
                        continue;

                    // A semi-palindrome needs length >= 2
                    if (i - j < 2)
                        continue;

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[j][parts - 1] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna