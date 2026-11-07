class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string cur = "";

        for (char c : s) {

            if (c == '(') {
                // Save the string before entering parentheses
                st.push(cur);
                cur = "";
            }
            else if (c == ')') {
                // Reverse the current substring
                reverse(cur.begin(), cur.end());

                // Add it to the string before '('
                cur = st.top() + cur;
                st.pop();
            }
            else {
                cur += c;
            }
        }

        return cur;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna