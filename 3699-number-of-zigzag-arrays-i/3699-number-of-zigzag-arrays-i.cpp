
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const long long MOD = 1000000007;
        int m = r - l + 1;

        // up[j]: arrays ending at j whose last step was increasing
        // down[j]: arrays ending at j whose last step was decreasing
        vector<long long> up(m), down(m);

        // Initialize arrays of length 2
        for (int j = 0; j < m; j++) {
            up[j] = j;
            down[j] = m - 1 - j;
        }

        // Extend arrays to length n
        for (int len = 3; len <= n; len++) {
            vector<long long> nextUp(m, 0);
            vector<long long> nextDown(m, 0);

            // Increasing last step: previous value must be smaller
            long long prefix = 0;
            for (int j = 0; j < m; j++) {
                nextUp[j] = prefix;
                prefix = (prefix + down[j]) % MOD;
            }

            // Decreasing last step: previous value must be larger
            long long suffix = 0;
            for (int j = m - 1; j >= 0; j--) {
                nextDown[j] = suffix;
                suffix = (suffix + up[j]) % MOD;
            }

            up = nextUp;
            down = nextDown;
        }

        long long ans = 0;

        for (int j = 0; j < m; j++) {
            ans = (ans + up[j] + down[j]) % MOD;
        }

        return (int)ans;
    }
};
