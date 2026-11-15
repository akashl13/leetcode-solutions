class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // pal[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = minimum cuts for s[0...i-1]
        vector<int> dp(n + 1);

        for (int i = 0; i <= n; i++)
            dp[i] = i - 1;

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j < i; j++) {

                if (pal[j][i - 1]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna