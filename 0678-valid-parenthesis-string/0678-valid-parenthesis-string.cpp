class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;      // '*' acts as ')'
                high++;     // '*' acts as '('
            }

            // Even the maximum possible '(' count is negative
            if (high < 0)
                return false;

            // low cannot be negative because '*' can be empty
            low = max(low, 0);
        }

        return low == 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna