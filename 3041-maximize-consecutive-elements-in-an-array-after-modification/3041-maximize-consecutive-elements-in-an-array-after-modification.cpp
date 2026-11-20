class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        const int MAXV = 1000002;
        vector<int> dp(MAXV, 0);

        int ans = 0;

        for (int x : nums) {
            int oldX = dp[x];
            int oldXm1 = dp[x - 1];
            int oldXp1 = dp[x + 1];

            dp[x] = max(oldX, oldXm1 + 1);
            dp[x + 1] = max(oldXp1, oldX + 1);

            ans = max(ans, max(dp[x], dp[x + 1]));
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna