class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(26, 0);
        long long total = 0;

        for (char c : s) {
            int idx = c - 'a';

            long long newCount = (total + 1) % MOD;

            total = (total + newCount - dp[idx] + MOD) % MOD;
            dp[idx] = newCount;
        }

        return total;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna