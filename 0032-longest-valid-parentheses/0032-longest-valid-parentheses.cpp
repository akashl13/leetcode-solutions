class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;

        // Base index
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {

                // Store index of '('
                st.push(i);

            } else {

                // Remove matching '('
                st.pop();

                if (st.empty()) {

                    // Current ')' cannot be matched
                    st.push(i);

                } else {

                    // Length of valid substring
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};