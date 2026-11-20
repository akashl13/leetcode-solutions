class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;

        for (char c : columnTitle) {
            result = result * 26 + (c - 'A' + 1);
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna