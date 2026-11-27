class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            // Free copies obtained by buying this item type.
            int freeCount = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % factor == 0) {
                    freeCount++;
                }
            }

            vector<int> ndp = dp;

            // Unbounded knapsack with an activation bonus.
            for (int b = price; b <= budget; b++) {

                // First purchased copy of this item.
                ndp[b] = max(ndp[b],
                             dp[b - price] + 1 + freeCount);

                // Additional purchased copies.
                if (b >= 2 * price) {
                    ndp[b] = max(ndp[b],
                                 ndp[b - price] + 1);
                }
            }

            dp = ndp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna