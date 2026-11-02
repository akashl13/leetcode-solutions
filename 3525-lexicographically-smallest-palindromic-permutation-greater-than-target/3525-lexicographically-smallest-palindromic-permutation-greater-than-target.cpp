class Solution {
public:
    string buildPalindrome(string left, char middle, int n) {
        string right = left;
        reverse(right.begin(), right.end());

        if (n % 2 == 1)
            return left + string(1, middle) + right;

        return left + right;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        // A palindrome can have at most one odd-frequency character.
        int oddCount = 0;
        char middle = '\0';

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                oddCount++;
                middle = char('a' + i);
            }
        }

        if (oddCount > 1)
            return "";

        // Build the character counts for the first half.
        vector<int> halfFreq(26, 0);
        for (int i = 0; i < 26; i++)
            halfFreq[i] = freq[i] / 2;

        int halfLen = n / 2;
        string targetHalf = target.substr(0, halfLen);

        // Match the longest possible prefix of targetHalf.
        vector<int> remaining = halfFreq;
        int matched = 0;

        while (matched < halfLen) {
            int x = targetHalf[matched] - 'a';

            if (remaining[x] == 0)
                break;

            remaining[x]--;
            matched++;
        }

        // If the complete first half matches, check that palindrome first.
        if (matched == halfLen) {
            string candidate = buildPalindrome(targetHalf, middle, n);

            if (candidate > target)
                return candidate;
        }

        // Change the rightmost possible position to a larger character.
        int pos = (matched == halfLen) ? halfLen - 1 : matched;

        for (; pos >= 0; pos--) {
            vector<int> rem = halfFreq;
            bool valid = true;

            // Preserve the prefix before this position.
            for (int j = 0; j < pos; j++) {
                int x = targetHalf[j] - 'a';

                if (rem[x] == 0) {
                    valid = false;
                    break;
                }

                rem[x]--;
            }

            if (!valid)
                continue;

            // Choose the smallest available character greater than target[pos].
            int targetChar = targetHalf[pos] - 'a';

            for (int c = targetChar + 1; c < 26; c++) {
                if (rem[c] == 0)
                    continue;

                string left = targetHalf.substr(0, pos);
                left += char('a' + c);
                rem[c]--;

                // Fill the remaining positions in ascending order.
                for (int k = 0; k < 26; k++) {
                    while (rem[k] > 0) {
                        left += char('a' + k);
                        rem[k]--;
                    }
                }

                return buildPalindrome(left, middle, n);
            }
        }

        return "";
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna