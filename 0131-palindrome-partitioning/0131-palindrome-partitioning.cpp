class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void backtrack(const string& s, int start) {
        // Entire string has been partitioned
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        // Try every possible substring
        for (int end = start; end < s.size(); end++) {

            // Only choose palindrome substrings
            if (isPalindrome(s, start, end)) {

                // Choose
                path.push_back(s.substr(start, end - start + 1));

                // Explore
                backtrack(s, end + 1);

                // Undo choice
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna