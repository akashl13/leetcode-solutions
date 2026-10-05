class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {

            if (c == '(') {
                // Start a new group
                st.push(0);
            }
            else {
                // Get the score inside the parentheses
                int inside = st.top();
                st.pop();

                // () = 1
                // (A) = 2 * A
                int score = (inside == 0) ? 1 : 2 * inside;

                // Add score to the previous level
                st.top() += score;
            }
        }

        return st.top();
    }
};