class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n + 1;

        vector<int> bit(2 * n + 5, 0);

        auto update = [&](int i) {
            while (i < (int)bit.size()) {
                bit[i]++;
                i += i & -i;
            }
        };

        auto query = [&](int i) {
            int sum = 0;
            while (i > 0) {
                sum += bit[i];
                i -= i & -i;
            }
            return sum;
        };

        int prefix = 0;
        long long ans = 0;

        // Initial prefix sum is 0.
        update(offset);

        for (int x : nums) {
            prefix += (x == target ? 1 : -1);

            // Count previous prefix sums strictly smaller than current.
            int idx = prefix + offset;
            ans += query(idx - 1);

            update(idx);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna