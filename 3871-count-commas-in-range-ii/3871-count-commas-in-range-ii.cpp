class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        // 1000 -> numbers with at least 1 comma
        // 1000000 -> numbers with at least 2 commas
        // etc.
        long long power = 1000;

        while (power <= n) {
            ans += n - power + 1;

            // Avoid overflow
            if (power > n / 1000)
                break;

            power *= 1000;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna