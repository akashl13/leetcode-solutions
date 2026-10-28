class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int n = s.size();
        int left = 0, ones = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < n; right++) {
            if (s[right] == '1') {
                ones++;
            }

            while (ones > k) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }

            while (ones == k) {
                int len = right - left + 1;
                string cur = s.substr(left, len);

                if (len < minLen || 
                    (len == minLen && (ans.empty() || cur < ans))) {
                    minLen = len;
                    ans = cur;
                }

                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna