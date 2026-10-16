class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;

        for (int x : nums) {
            xr ^= x;
        }

        if (xr != 0) {
            return nums.size();
        }

        for (int x : nums) {
            if (x != 0) {
                return nums.size() - 1;
            }
        }

        return 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna