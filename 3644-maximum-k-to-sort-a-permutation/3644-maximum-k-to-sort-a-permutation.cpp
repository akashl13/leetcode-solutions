class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                if (k == -1)
                    k = nums[i];
                else
                    k &= nums[i];
            }
        }

        return max(k, 0);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna