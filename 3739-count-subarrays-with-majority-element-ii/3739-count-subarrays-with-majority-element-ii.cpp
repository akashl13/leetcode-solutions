class Solution {
public:

    void update(vector<int>& bit, int index) {
        int n = bit.size();

        while (index < n) {
            bit[index]++;
            index += index & (-index);
        }
    }

    int query(vector<int>& bit, int index) {
        int sum = 0;

        while (index > 0) {
            sum += bit[index];
            index -= index & (-index);
        }

        return sum;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // Shift prefix sums so all Fenwick indices are positive
        int offset = n + 1;

        vector<int> bit(2 * n + 3, 0);

        long long ans = 0;
        int prefix = 0;

        // Store initial prefix sum = 0
        update(bit, prefix + offset);

        for (int x : nums) {

            // Convert:
            // target     -> +1
            // non-target -> -1
            if (x == target)
                prefix++;
            else
                prefix--;

            int index = prefix + offset;

            // Count previous prefix sums smaller than current
            ans += query(bit, index - 1);

            // Store current prefix
            update(bit, index);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna