class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        // Count frequency of each letter
        for (char c : word) {
            freq[c - 'a']++;
        }

        // Highest frequency first
        sort(freq.rbegin(), freq.rend());

        int ans = 0;

        // 8 keys, so every 8 letters increase the push count
        for (int i = 0; i < 26; i++) {
            int pushes = i / 8 + 1;
            ans += freq[i] * pushes;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna