class Solution {
public:

    void backtrack(int n, int open, int close,
                   string current,
                   vector<string>& result) {

        // If we used all parentheses
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // We can add '(' if we haven't used all n
        if (open < n) {
            backtrack(n, open + 1, close,
                      current + "(", result);
        }

        // We can add ')' only if there are unmatched '('
        if (close < open) {
            backtrack(n, open, close + 1,
                      current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> result;

        backtrack(n, 0, 0, "", result);

        return result;
    }
};