class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        // Smallest number is odd:
        // Every even number can subtract this odd number
        // and become odd.
        if (mn % 2 == 1)
            return true;

        // Smallest number is even:
        // It cannot change, so every number must be even.
        for (int x : nums1) {
            if (x % 2 == 1)
                return false;
        }

        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna