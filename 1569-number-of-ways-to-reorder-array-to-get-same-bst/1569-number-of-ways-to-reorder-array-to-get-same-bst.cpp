class Solution {
public:
    using ll = long long;
    static const int MOD = 1e9 + 7;

    vector<vector<ll>> comb;

    ll solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        ll waysLeft = solve(left);
        ll waysRight = solve(right);

        ll ways = comb[n - 1][left.size()];
        ways = ways * waysLeft % MOD;
        ways = ways * waysRight % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        comb.assign(n + 1, vector<ll>(n + 1, 1));

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] +
                              comb[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna