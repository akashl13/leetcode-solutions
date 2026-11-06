class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Already sorted
        bool sorted = true;

        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                sorted = false;
                break;
            }
        }

        if (sorted)
            return 0;

        // With only two characters, the only useful
        // substring would be the whole string, which is forbidden.
        if (n == 2)
            return -1;

        // Find minimum and maximum characters
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // If minimum is already at the beginning,
        // or maximum is already at the end,
        // one operation is enough.
        if (s[0] == mn || s[n - 1] == mx)
            return 1;

        // If minimum or maximum exists somewhere in the middle,
        // two operations are enough.
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx)
                return 2;
        }

        // Minimum is only at the end and maximum is only at
        // the beginning, with no useful extreme in the middle.
        return 3;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna