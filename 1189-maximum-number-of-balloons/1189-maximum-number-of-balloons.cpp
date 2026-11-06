class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);

        // Count characters
        for (char c : text) {
            freq[c - 'a']++;
        }

        // Required:
        // b = 1
        // a = 1
        // l = 2
        // o = 2
        // n = 1

        int ans = INT_MAX;

        ans = min(ans, freq['b' - 'a']);
        ans = min(ans, freq['a' - 'a']);
        ans = min(ans, freq['l' - 'a'] / 2);
        ans = min(ans, freq['o' - 'a'] / 2);
        ans = min(ans, freq['n' - 'a']);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna