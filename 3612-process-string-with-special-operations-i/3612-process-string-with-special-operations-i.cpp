class Solution {
public:
    string processStr(string s) {
        string result;

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                result += c;
            }
            else if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            }
            else if (c == '#') {
                result += result;
            }
            else if (c == '%') {
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna