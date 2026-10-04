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
                // '*' can be '(' or ')' or empty
                low--;
                high++;
            }

            // Even the maximum possible balance is negative
            if (high < 0)
                return false;

            // Balance cannot actually be negative
            low = max(low, 0);
        }

        // Valid if we can end with exactly 0 unmatched '('
        return low == 0;
    }
};