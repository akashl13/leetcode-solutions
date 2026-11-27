class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression))
            return memo[expression];

        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {
            char op = expression[i];

            if (op == '+' || op == '-' || op == '*') {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> L = diffWaysToCompute(left);
                vector<int> R = diffWaysToCompute(right);

                for (int a : L) {
                    for (int b : R) {
                        if (op == '+')
                            ans.push_back(a + b);
                        else if (op == '-')
                            ans.push_back(a - b);
                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        // If there is no operator, it's a number.
        if (ans.empty())
            ans.push_back(stoi(expression));

        return memo[expression] = ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna