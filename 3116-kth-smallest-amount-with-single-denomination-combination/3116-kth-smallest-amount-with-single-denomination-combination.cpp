
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        vector<pair<long long, int>> subsets;

        // Generate every non-empty subset and its LCM
        for (int mask = 1; mask < (1 << n); mask++) {
            long long l = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    long long g = gcd(l, (long long)coins[i]);
                    l = l / g * coins[i];

                    if (l > 1LL * k * (*min_element(coins.begin(), coins.end()))) {
                        break;
                    }
                }
            }

            subsets.push_back({l, bits});
        }

        long long left = 1;
        long long right = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;

            for (auto [l, bits] : subsets) {
                if (l > mid) continue;

                long long amount = mid / l;

                if (bits % 2 == 1)
                    count += amount;
                else
                    count -= amount;
            }

            if (count >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna