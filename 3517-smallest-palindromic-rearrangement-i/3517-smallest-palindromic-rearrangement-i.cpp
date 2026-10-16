class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string half = "";
        char mid = '\0';

        for (int i = 0; i < 26; i++) {
            half.append(freq[i] / 2, char('a' + i));

            if (freq[i] % 2 == 1) {
                mid = char('a' + i);
            }
        }

        string rev = half;
        reverse(rev.begin(), rev.end());

        if (mid != '\0') {
            return half + mid + rev;
        }

        return half + rev;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna