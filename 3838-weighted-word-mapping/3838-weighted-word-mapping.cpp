class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (string& word : words) {
            int sum = 0;

            for (char c : word) {
                sum += weights[c - 'a'];
            }

            int rem = sum % 26;
            ans += char('z' - rem);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna