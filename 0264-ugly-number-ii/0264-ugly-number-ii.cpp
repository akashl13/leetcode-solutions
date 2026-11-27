class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);

        dp[0] = 1;

        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; i++) {
            int a = dp[p2] * 2;
            int b = dp[p3] * 3;
            int c = dp[p5] * 5;

            dp[i] = min({a, b, c});

            if (dp[i] == a) p2++;
            if (dp[i] == b) p3++;
            if (dp[i] == c) p5++;
        }

        return dp[n - 1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna