class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;

        int depth = 0;

        for (char c : seq) {

            if (c == '(') {
                depth++;

                // Assign based on current depth
                ans.push_back(depth % 2);
            }
            else {
                // Closing bracket belongs to the same
                // nesting level as its matching opening bracket
                ans.push_back(depth % 2);

                depth--;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna