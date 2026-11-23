
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        // If k is large enough, unlimited transactions are possible.
        if (k >= n / 2) {
            int profit = 0;

            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }

            return profit;
        }

        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);

        for (int price : prices) {

            for (int t = 1; t <= k; t++) {

                buy[t] = max(buy[t], sell[t - 1] - price);

                sell[t] = max(sell[t], buy[t] + price);
            }
        }

        return sell[k];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna