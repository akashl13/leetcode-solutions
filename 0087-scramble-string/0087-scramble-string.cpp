class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(string& s1, string& s2, int i, int j, int len) {
        string key = to_string(i) + "," + to_string(j) + "," + to_string(len);

        if (memo.count(key)) {
            return memo[key];
        }

        if (s1.substr(i, len) == s2.substr(j, len)) {
            return memo[key] = true;
        }

        int freq[26] = {};

        for (int k = 0; k < len; k++) {
            freq[s1[i + k] - 'a']++;
            freq[s2[j + k] - 'a']--;
        }

        for (int x : freq) {
            if (x != 0) {
                return memo[key] = false;
            }
        }

        for (int k = 1; k < len; k++) {
            // No swap
            if (solve(s1, s2, i, j, k) &&
                solve(s1, s2, i + k, j + k, len - k)) {
                return memo[key] = true;
            }

            // Swap
            if (solve(s1, s2, i, j + len - k, k) &&
                solve(s1, s2, i + k, j, len - k)) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        memo.clear();
        return solve(s1, s2, 0, 0, s1.size());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna