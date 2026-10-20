
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 0);

        function<int(int)> dfs = [&](int i) -> int {
            if (dp[i] != 0) return dp[i];

            dp[i] = 1;

            // Jump to the left
            for (int j = i - 1; j >= max(0, i - d); j--) {
                if (arr[j] >= arr[i]) break;

                dp[i] = max(dp[i], 1 + dfs(j));
            }

            // Jump to the right
            for (int j = i + 1; j <= min(n - 1, i + d); j++) {
                if (arr[j] >= arr[i]) break;

                dp[i] = max(dp[i], 1 + dfs(j));
            }

            return dp[i];
        };

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i));
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna