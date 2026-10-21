
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, INT_MAX);

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];

            if (c >= 'a' && c <= 'z') {
                lastLower[c - 'a'] = i;
            } else {
                firstUpper[c - 'A'] = min(firstUpper[c - 'A'], i);
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 &&
                firstUpper[i] != INT_MAX &&
                lastLower[i] < firstUpper[i]) {
                ans++;
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna