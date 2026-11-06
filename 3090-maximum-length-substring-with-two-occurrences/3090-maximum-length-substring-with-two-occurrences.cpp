class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            freq[s[right] - 'a']++;

            // If any character appears more than 2 times,
            // shrink the window from the left.
            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            // Current window is valid
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna