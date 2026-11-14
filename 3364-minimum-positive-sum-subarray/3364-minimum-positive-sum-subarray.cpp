class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;

        // Try every starting position
        for (int i = 0; i < n; i++) {
            int sum = 0;

            // Extend the subarray
            for (int j = i; j < n; j++) {
                sum += nums[j];

                int len = j - i + 1;

                // Length must be between l and r
                if (len >= l && len <= r && sum > 0) {
                    ans = min(ans, sum);
                }

                // No need to make it longer than r
                if (len >= r)
                    break;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna