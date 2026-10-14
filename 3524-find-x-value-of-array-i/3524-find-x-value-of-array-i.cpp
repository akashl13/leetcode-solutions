class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next(k, 0);
            int r = num % k;

            // Start a new subarray
            next[r]++;

            // Extend previous subarrays
            for (int rem = 0; rem < k; rem++) {
                int newRem = (1LL * rem * r) % k;
                next[newRem] += dp[rem];
            }

            dp = next;

            // Count all subarrays ending here
            for (int rem = 0; rem < k; rem++) {
                result[rem] += dp[rem];
            }
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna