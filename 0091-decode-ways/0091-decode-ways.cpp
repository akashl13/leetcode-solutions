
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if (n == 0 || s[0] == '0')
            return 0;

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            // Decode one digit
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // Decode two digits
            int twoDigits = (s[i - 2] - '0') * 10
                          + (s[i - 1] - '0');

            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna