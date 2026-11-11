class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;

        // up[x]   = sequences ending at x where last move was increasing
        // down[x] = sequences ending at x where last move was decreasing
        vector<long long> up(m), down(m);

        // For length 2
        for (int x = 0; x < m; x++) {
            // Previous value < x
            up[x] = x;

            // Previous value > x
            down[x] = m - 1 - x;
        }

        // Build arrays of length 3 ... n
        for (int len = 3; len <= n; len++) {
            vector<long long> newUp(m, 0);
            vector<long long> newDown(m, 0);

            // Prefix sums
            vector<long long> prefixUp(m + 1, 0);
            vector<long long> prefixDown(m + 1, 0);

            for (int i = 0; i < m; i++) {
                prefixUp[i + 1] =
                    (prefixUp[i] + up[i]) % MOD;

                prefixDown[i + 1] =
                    (prefixDown[i] + down[i]) % MOD;
            }

            for (int x = 0; x < m; x++) {
                // Last move is increasing:
                // previous value must be < x
                // and before that the move must have been decreasing.
                newUp[x] = prefixDown[x];

                // Last move is decreasing:
                // previous value must be > x
                // and before that the move must have been increasing.
                newDown[x] =
                    (prefixUp[m] - prefixUp[x + 1] + MOD) % MOD;
            }

            up = newUp;
            down = newDown;
        }

        long long ans = 0;

        for (int x = 0; x < m; x++) {
            ans = (ans + up[x] + down[x]) % MOD;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna