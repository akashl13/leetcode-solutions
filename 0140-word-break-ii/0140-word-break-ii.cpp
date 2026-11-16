class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> solve(string &s, int start) {
        // If we reached the end
        if (start == s.length()) {
            return {""};
        }

        // Already calculated
        if (memo.count(start)) {
            return memo[start];
        }

        vector<string> result;

        for (int end = start + 1; end <= s.length(); end++) {
            string word = s.substr(start, end - start);

            // If current substring is a dictionary word
            if (dict.count(word)) {

                vector<string> rest = solve(s, end);

                for (string sentence : rest) {
                    if (sentence.empty()) {
                        result.push_back(word);
                    } else {
                        result.push_back(word + " " + sentence);
                    }
                }
            }
        }

        return memo[start] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());

        return solve(s, 0);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna