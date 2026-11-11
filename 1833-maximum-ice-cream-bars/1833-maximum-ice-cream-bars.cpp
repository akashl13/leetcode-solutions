
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> freq(100001, 0);

        // Count the frequency of each cost
        for (int cost : costs) {
            freq[cost]++;
        }

        int count = 0;

        // Buy the cheapest bars first
        for (int cost = 1; cost <= 100000; cost++) {
            while (freq[cost] > 0 && coins >= cost) {
                coins -= cost;
                count++;
                freq[cost]--;
            }

            if (coins < cost) {
                break;
            }
        }

        return count;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna