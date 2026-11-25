
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);

        // Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        string st = "";

        for (char c : s) {
            int idx = c - 'a';

            freq[idx]--;

            // Skip if character is already included
            if (visited[idx])
                continue;

            // Remove larger characters if they appear again later
            while (!st.empty() && st.back() > c &&
                   freq[st.back() - 'a'] > 0) {

                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            visited[idx] = true;
        }

        return st;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna