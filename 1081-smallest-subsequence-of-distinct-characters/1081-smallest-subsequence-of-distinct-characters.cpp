class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26, -1);
        vector<bool> used(26, false);
        string st;

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            int idx = c - 'a';

            if (used[idx])
                continue;

            while (!st.empty() &&
                   st.back() > c &&
                   last[st.back() - 'a'] > i) {
                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            used[idx] = true;
        }

        return st;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna