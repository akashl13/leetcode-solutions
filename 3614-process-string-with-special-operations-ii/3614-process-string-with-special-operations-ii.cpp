class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n + 1, 0);

        // Calculate result length after each operation
        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (c >= 'a' && c <= 'z')
                len[i + 1] = len[i] + 1;
            else if (c == '*')
                len[i + 1] = max(0LL, len[i] - 1);
            else if (c == '#')
                len[i + 1] = len[i] * 2;
            else
                len[i + 1] = len[i];
        }

        if (k >= len[n])
            return '.';

        // Work backwards to find the character at index k
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                if (k == len[i])
                    return c;
            }
            else if (c == '*') {
                // Deletion doesn't change the index of earlier characters
            }
            else if (c == '#') {
                if (k >= len[i])
                    k -= len[i];
            }
            else if (c == '%') {
                k = len[i] - 1 - k;
            }
        }

        return '.';
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna