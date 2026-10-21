
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end()))
            return 0;

        if (n == 2)
            return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // One operation is enough if either endpoint
        // is already correctly positioned.
        if (s[0] == mn || s[n - 1] == mx)
            return 1;

        // Two operations are enough if the minimum
        // occurs before the last position, or the
        // maximum occurs after the first position.
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == mn)
                return 2;
        }

        for (int i = 1; i < n; i++) {
            if (s[i] == mx)
                return 2;
        }

        // Both extremes are trapped at opposite ends.
        return 3;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna