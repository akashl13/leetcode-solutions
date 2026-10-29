class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(m + 1, n);
        int j = m - 1;

        // Find positions matching the suffix of word2.
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                suf[j] = i;
                --j;
            }
        }

        vector<int> ans;
        int matched = 0;
        bool usedMismatch = false;

        for (int i = 0; i < n && matched < m; ++i) {
            if (word1[i] == word2[matched]) {
                ans.push_back(i);
                ++matched;
            } 
            else if (!usedMismatch) {
                int next = matched + 1;

                // The remaining suffix must be matchable.
                if (next == m || suf[next] != n) {
                    if (next == m || suf[next] > i) {
                        ans.push_back(i);
                        ++matched;
                        usedMismatch = true;
                    }
                }
            }
        }

        if (matched != m) {
            return {};
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna