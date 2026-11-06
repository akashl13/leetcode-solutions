class Solution {
public:
    static const long long MOD = 1000000007;

    long long C[1001][1001];

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return 1;

        int root = nums[0];

        vector<int> left;
        vector<int> right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        // Number of ways to arrange left and right
        // while keeping their internal order valid.
        long long ways = C[n - 1][left.size()];

        ways = ways * solve(left) % MOD;
        ways = ways * solve(right) % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {

        int n = nums.size();

        // Precompute combinations C[n][r]
        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;

            for (int j = 1; j < i; j++) {
                C[i][j] =
                    (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        // Original ordering itself is included,
        // but the question asks for OTHER reorderings.
        return (solve(nums) - 1 + MOD) % MOD;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna