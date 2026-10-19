class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<long long> freq(maxVal + 1, 0);

        for (int x : nums) {
            freq[x]++;
        }

        // Count pairs whose GCD is exactly g.
        vector<long long> count(maxVal + 1, 0);

        for (int g = maxVal; g >= 1; g--) {
            long long total = 0;

            for (int multiple = g; multiple <= maxVal; multiple += g) {
                total += freq[multiple];
            }

            // Number of pairs where both numbers are divisible by g.
            long long pairs = total * (total - 1) / 2;

            count[g] = pairs;

            // Remove pairs whose GCD is a multiple of g greater than g.
            for (int multiple = 2 * g; multiple <= maxVal; multiple += g) {
                count[g] -= count[multiple];
            }
        }

        // Prefix sums: number of pairs with GCD <= g.
        vector<long long> prefix(maxVal + 1, 0);

        for (int g = 1; g <= maxVal; g++) {
            prefix[g] = prefix[g - 1] + count[g];
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1,
                                prefix.end(), q + 1) - prefix.begin();
            answer.push_back(g);
        }

        return answer;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna