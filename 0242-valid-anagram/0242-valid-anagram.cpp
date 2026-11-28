
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> freq(26, 0);

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna